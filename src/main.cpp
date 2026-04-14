#include <iostream>
#include <vector>

using namespace std;
enum Keyword {
  SET,
  GET,
  DEL,
  WORD,
};
struct Token {
  Keyword type;
  string value;
};
Keyword stringToKeyword(const string &str);
Token makeToken(Keyword keyword, string value);

vector<Token> tokenize(string input) {
  vector<Token> tokens;
  string aux = "";
  Keyword key;
  Token token;
  if (input.empty()) {
    cout << "Empty string";
  }
  for (char c : input) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (!aux.empty()) {
        key = stringToKeyword(aux);
        token = makeToken(key, aux);
        tokens.push_back(token);
        aux = "";
      }

    } else {
      aux = aux + c;
    }
  }
  if (!aux.empty()) {
    key = stringToKeyword(aux);
    token = makeToken(key, aux);
    tokens.push_back(token);
  }
  return tokens;
}

Keyword stringToKeyword(const string &str) {
  if (str == "SET") {
    return Keyword::SET;
  } else if (str == "GET") {
    return Keyword::GET;
  } else if (str == "DEL") {
    return Keyword::DEL;
  } else {
    return Keyword::WORD;
  }
}

Token makeToken(Keyword keyword, string value) {
  Token t;
  t.type = keyword;
  t.value = value;
  return t;
}

int main() {
  string input = "SET key value";
  vector<Token> parseT = tokenize(input);
  for (Token i : parseT) {
    cout << i.value << "\n";
  }
  return 0;
}
