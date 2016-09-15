//
// Created by jeanpolalvarado on 08/09/16.
//

#include "Token.h"
typedef vector<char> char_array;

char_array charset() {
    return char_array(
            {'0','1','2','3','4',
             '5','6','7','8','9',
             'A','B','C','D','E','F',
             'G','H','I','J','K',
             'L','M','N','O','P',
             'Q','R','S','T','U',
             'V','W','X','Y','Z',
             'a','b','c','d','e','f',
             'g','h','i','j','k',
             'l','m','n','o','p',
             'q','r','s','t','u',
             'v','w','x','y','z'
            });
};

// given a function that generates a random character,
// return a string of the requested length
/**
 * Genera una cadena de caracteres de manera random
 * @param length Que tan largo sera el Token
 * @param rand_char CUal es el rango a utilizar para el random(), sera el vector
 * @return Retorna una cadena de 8 caracteres de manera random
 */
string random_string( size_t length, std::function<char(void)> rand_char ){
    std::string str(length,0);
    std::generate_n( str.begin(), length, rand_char );
    return str;
}
string Token::generateToken() {
        const auto ch_set = charset();
        default_random_engine rng(std::random_device{}());
        uniform_int_distribution<> dist(0, ch_set.size()-1);
        auto randchar = [ ch_set,&dist,&rng ](){return ch_set[ dist(rng) ];};
        auto length = 8;
        string flag=random_string(length,randchar);
        return flag;
}

///////////////////GETERS/SETTERS////////////////////////////////
const string &Token::getToken() const {return token; }
void Token::setToken(){Token::token = generateToken();}



