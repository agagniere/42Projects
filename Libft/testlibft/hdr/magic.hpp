// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   type_traits.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/11/23 14:36:46 by ngoguey           #+#    #+#             //
/*   Updated: 2015/11/30 13:01:31 by angagnie         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#ifndef FT_TYPE_TRAITS_HPP
# define FT_TYPE_TRAITS_HPP

# include <type_traits>
# include <ostream>

#define ISSAME(A, B) std::is_same<A, B>::value
#define OK_IF(PRED) typename std::enable_if<PRED>::type* = nullptr

namespace ft // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
{ // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

namespace dont_drool // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
{ // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

template <class _CharT, class _Traits, class T>
int		&operator<<(std::basic_ostream<_CharT, _Traits>&, const T&);

template<typename T>
struct is_printable
{
	using Ret = decltype((*(std::ostream*)(0x0)) << (*(T*)(0x0)));

	static constexpr bool	value = std::is_same<Ret, std::ostream&>::value
													|| std::is_convertible<T, std::string>::value
													|| std::is_same<T, void *>::value
													;
};
}; // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ END OF NAMESPACE DONT_DROOL //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

template<typename T>
struct is_printable
{
	static constexpr bool	value = dont_drool::is_printable<T>::value;
};

}; // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ END OF NAMESPACE FT //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

# undef OK_IF

#endif /* ************************************************ FT_TYPE_TRAITS_HPP */

#ifndef UTILS_H
# define UTILS_H

# include <iostream>
# include <ostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <tuple>


namespace ft
{

/*
** Compute 'format' and return a new string
** format: the '%' is used to substitute arguments
** std::ostream::operator<< is used for convertions
*/
template<typename ... ARGS>
std::string			f(char const *format, ARGS ...args);

/*
** Same but write into 'out'
*/
template<typename ... ARGS>
void				f(std::ostream &out, char const *format, ARGS ...args);

/*
** Impl
*/
static inline char const	*f_print(std::ostream &out, char const *format)
{
	while (*format != '\0' && *format != '%')
		out << *(format++);
	return (format);
}

static inline void			f_loop(std::ostream &out, char const *format)
{
	out << format;
}

template<typename HEAD, typename ... TAIL>
void				f_loop(std::ostream &out, char const *format,
						   HEAD&& arg, TAIL&& ...tail)
{
	if (*format != '%')
	{
		f_loop(out, format);
		return ;
	}
	out << arg;
	f_loop(out, f_print(out, format + 1), std::forward<TAIL>(tail)...);
}

template<typename ... ARGS>
std::string			f(char const *format, ARGS ...args)
{
	std::ostringstream	out;

	f_loop(out, f_print(out, format), std::forward<ARGS>(args)...);
	return (out.str());
}

template<typename ... ARGS>
void				f(std::ostream &out, char const *format, ARGS ...args)
{
	f_loop(out, f_print(out, format), std::forward<ARGS>(args)...);
}



/*
** valtostring
*/
namespace internal // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
{ // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
template <bool, class T>
struct Stringify {};

template <class T>
struct Stringify<true, T>
{
	static std::string	toString(T const&v) { return ft::f("%", v); }
};

template <class T>
struct Stringify<false, T>
{
	static char const	*toString(T const&) { return typeid(T).name(); }
};
}; // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ END OF NAMESPACE INTERNAL //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //


# define OK_IF(PRED) typename std::enable_if<PRED>::type* = nullptr
# define ISPTR(A) std::is_pointer<A>::value

template <class T
		  , OK_IF(!ISSAME(T, char const *))
		  , OK_IF(!ISSAME(T, char *))
		  >
std::string				valToString(T const &v)
{
	return internal::Stringify<ft::is_printable<T>::value, T>::toString(v);
}

inline std::string		valToString(char const *v)
{
	return std::string("\"") + v + "\"";
}

# undef OK_IF
# undef ISPTR

// tupletostring ============================================================ //
//
namespace internal // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
{ // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

inline std::string		_variadictostring(void)
{
	return "";
}

template <class Head>
std::string				_variadictostring(Head const &v)
{
	return valToString(v);
}

template <class Head, class ...Tail>
std::string				_variadictostring(Head const &v, Tail const &...tail)
{
	return valToString(v) + ", " + _variadictostring(tail...);
}

# define OK_IF(PRED) typename std::enable_if<PRED>::type* = nullptr
template <size_t I
		  , typename... ARGS
		  , OK_IF((sizeof...(ARGS) - I == 1))
		  >
std::string				_tupletostring(std::tuple<ARGS...> const &wrap)
{
	return valToString(std::get<I>(wrap));
}

template <size_t I
		  , typename... ARGS
		  , OK_IF((sizeof...(ARGS) - I != 1))
		  >
std::string				_tupletostring(std::tuple<ARGS...> const &wrap)
{

	return valToString(std::get<I>(wrap)) + ", "
		+ _tupletostring<I + 1>(wrap);
}

inline std::string		_typestostring(void)
{
	return "";
}
template <class Head>
std::string				_typestostring(void)
{
	return std::string(typeid(Head).name());
}
template <class Head, class Head2, class... Args>
std::string				_typestostring(void)
{
	return std::string(typeid(Head).name()) + ", "
		+ _typestostring<Head2, Args...>();
}

# undef OK_IF

}; // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ END OF NAMESPACE INTERNAL //
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

template <class ...Args>
std::string				variadicToString(Args const &...args)
{
	return internal::_variadictostring(args...);
}

template <class ...Args>
std::string				tupleToString(std::tuple<Args...> const &tup)
{
	return internal::_tupletostring<0>(tup);
}

template <class ...Args>
std::string				typesToString(void)
{
	return internal::_typestostring<Args...>();
}

};

#endif
/*
template <typename F, typename ...Args>
void			launchTest(F f, char const *funname, Args ...args)
{
	std::cout << ft::variadicToString(f, funname, args...) << std::endl;
	auto 	ret = f(args...);

	std::cout << "return: " << ft::valToString(ret) << std::endl;

	return ;
}

#define LAUNCHTEST(FUN, ...) launchTest(FUN, #FUN, __VA_ARGS__)

int							main(void)
{
	char  dst[70];
	char const *src = "salut";

	LAUNCHTEST(memcpy, (char*)dst, src, strlen(src));
	LAUNCHTEST(strlen, dst);

	return (0);
}
*/
