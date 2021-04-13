#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#ifndef HASHMAP_CAPACITY
# define HASHMAP_CAPACITY 16384
#endif

typedef struct string
{
    char*  string;
    size_t length;
} t_string;

#define STRING(STR, LEN) (t_string){ .string = STR, .length = LEN }
#define STRING_NULL STRING(NULL, 0)

typedef struct hm_node
{
    struct hm_node* next;
    t_string key;
    t_string value;
    size_t   hash;
} t_hm_node;

# define EMPTY_NODE (void*)(0xDEADBEEF)

typedef struct hashmap
{
    t_hm_node* data;
    size_t capacity;
} t_hashmap;

size_t fnv1a_32(t_string key)
{
    uint32_t hash, c;

    hash = 2166136261;
    while (key.length --> 0)
    {
        c = (unsigned char)*(key.string)++;
        hash ^= c;
        hash *= 16777619;
    }
    return hash;
}

size_t fnv1a_64(t_string key)
{
    uint64_t hash, c;

    hash = 14695981039346656037UL;
    while (key.length --> 0)
    {
        c = (unsigned char)*(key.string)++;
        hash ^= c;
        hash *= 1099511628211UL;
    }
    return hash;
}

size_t djb2a(t_string key)
{
    uint32_t hash, c;

    hash = 5381;
    while (key.length --> 0)
    {
        c = (unsigned char)*(key.string)++;
        hash = ((hash << 5) + hash) ^ c;
    }
    return (size_t)hash;
}

#define ft_hash fnv1a_64

void* ft_memdup(const void* src, size_t len)
{
    void* dst;

    if ((dst = malloc(len)))
        memcpy(dst, src, len);
    return dst;
}

bool hashmap_remove(t_hashmap* map, const t_string* key)
{
    size_t hash = ft_hash(*key);
    t_hm_node* ptr = map->data + (hash % map->capacity);
    t_hm_node* prev = NULL;

    if (ptr->next == EMPTY_NODE)
        return false;
    while (ptr != NULL
           && (ptr->hash != hash || strncmp(key->string, ptr->key.string, key->length) != 0))
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL)
        return false;
    free(ptr->key.string);
    free(ptr->value.string);
    if (prev == NULL)
    {
        if (ptr->next == NULL)
        {
            ptr->next = EMPTY_NODE;
            return true;
        }
        prev = ptr;
        ptr = ptr->next;
        memcpy(prev, ptr, sizeof(t_hm_node));
    }
    else
        prev->next = ptr->next;
    free(ptr);
    return true;
}

/* If key is already present, do nothing */
bool hashmap_add(t_hashmap* map, const t_string* key, const t_string* value)
{
    size_t hash = ft_hash(*key);
    t_hm_node* dest = map->data + (hash % map->capacity);
    t_hm_node* prev = NULL;

    if (dest->next != EMPTY_NODE)
    {
        while (dest != NULL
               && (dest->hash != hash || strncmp(key->string, dest->key.string, key->length) != 0))
        {
            prev = dest;
            dest = dest->next;
        }
        if (dest != NULL)
            return false;
        dest = malloc(sizeof(t_hm_node));
        prev->next = dest;
    }
    dest->next = NULL;
    dest->hash = hash;
    dest->key.string = ft_memdup(key->string, key->length + 1);
    dest->key.string[key->length] = '\0';
    dest->key.length = key->length;
    dest->value.string = ft_memdup(value->string, value->length + 1);
    dest->value.string[value->length] = '\0';
    dest->value.length = value->length;
    return true;
}

bool hashmap_get(const t_hashmap* map, const t_string* key, t_string* out_result)
{
    size_t hash = ft_hash(*key);
    const t_hm_node* ptr = map->data + (hash % map->capacity);

    if (ptr->next == EMPTY_NODE)
        return false;
    while (ptr != NULL
           && (ptr->hash != hash || strncmp(key->string, ptr->key.string, key->length) != 0))
        ptr = ptr->next;
    if (ptr == NULL)
        return false;
    *out_result = ptr->value;
    return true;
}

void hashmap_print(const t_hashmap* map)
{
    printf("---------------------------------------------\n");
    for (unsigned i = 0; i < map->capacity ; i++)
    {
        if (map->data[i].next != EMPTY_NODE)
        {
            printf("%u : ", i);
            t_hm_node* ptr = map->data + i;
            while (ptr)
            {
                printf(" -> (%.*s, %.*s)", (int)ptr->key.length, ptr->key.string, (int)ptr->value.length, ptr->value.string);
                ptr = ptr->next;
            }
            printf("\n");
        }
    }
}

void hm_node_clear(t_hm_node* node)
{
    if (node->next)
        hm_node_clear(node->next);
    free(node->key.string);
    free(node->value.string);
    free(node);
}

void hashmap_clear(t_hashmap* map)
{
    t_hm_node* ptr = map->data + map->capacity;

    while (ptr --> map->data)
    {
        if (ptr->next == EMPTY_NODE)
            continue;
        if (ptr->next)
            hm_node_clear(ptr->next);
        free(ptr->key.string);
        free(ptr->value.string);
    }
    free(map->data);
    map->data = NULL;
    map->capacity = 0;
}

int main(void)
{
    t_string line = STRING_NULL;
    size_t getline_size;
    ssize_t read;
    t_hashmap map;
    size_t equal;
    t_string key, value;

    if (!(map.data = calloc(HASHMAP_CAPACITY, sizeof(t_hm_node))))
        return 1;
    map.capacity = HASHMAP_CAPACITY;
    for (unsigned i = 0; i < map.capacity; i++)
        map.data[i].next = EMPTY_NODE;
    while ((read = getline(&(line.string), &getline_size, stdin)) >= 0)
    {
        if (read == 0)
            continue;
        line.length = read - 1;
        if (line.string[0] == '!')
        {
            key.string = line.string + 1;
            key.length = line.length - 1;
            hashmap_remove(&map, &key);
        }
        else
        {
            equal = 0;
            while (line.string[equal] != '\0' && line.string[equal] != '=')
                ++equal;
            if (line.string[equal] == '\0')
            {
                if (hashmap_get(&map, &line, &value))
                    printf("%.*s\n", (int)value.length, value.string);
                else
                    printf("%.*s: Not Found\n", (int)line.length, line.string);
            }
            else
            {
                key.string = line.string;
                key.length = equal;
                value.string = line.string + equal + 1;
                value.length = line.length - equal - 1;
                hashmap_add(&map, &key, &value);
            }
        }
    }
    hashmap_print(&map);
    hashmap_clear(&map);
    free(line.string);
    return 0;
}
