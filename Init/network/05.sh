nslookup slash16.org | grep -oP 'Server:\s+\K[\d.]+'
dig slash16.org | grep -oP 'SERVER: [\d.#]+\(\K[\d.]+'
