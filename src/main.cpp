#include <iostream>
#include <vector>

using namespace std;
enum Keyword {
  SET,
  GET,
  DEL,
  WORD,
};

enum class ErrorCode {
  OK = 0,
  Emptystring,
};

struct SetCommand {
  string key;
  string value;
};
struct GetCommand {
  string key;
};
struct DelCommand {
  string key;
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
  // cout << input << "\n";
  if (input.empty()) {
    cerr << "Empty String";
    exit(1); // not ideal for REPL
  }
  for (char c : input) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (!aux.empty()) {
        key = stringToKeyword(aux);
        token = makeToken(key, aux);
        tokens.push_back(token); // add the token to the vector
        aux = "";
      }

    } else {
      aux = aux + c;
    }
  }
  if (!aux.empty()) { // for the last string
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

void parseToken(vector<Token>& parseT) {
  size_t args = parseT.size();
  if (parseT[0].type == Keyword::SET) {
    if (args == 3) {
      // cout << "SET \n";
      SetCommand command;
      command.key = parseT[1].value;
      command.value = parseT[2].value;
      cout << "SetCommand: key= " << command.key << ", value= " << command.value
           << "\n";

    } else {
      cerr << "Error length";
      return;
    }
  } else if (parseT[0].type == Keyword::GET) {
    if (args == 2) {
      // cout << "GET";
      GetCommand command;
      command.key = parseT[1].value;
      cout << "GetCommand: key= " << command.key << "\n";

    } else {
      cerr << "Error length";
      return;
    }
  } else if (parseT[0].type == Keyword::DEL) {
    if (args == 2) {
      // cout << "DEL";
      DelCommand command;
      command.key = parseT[1].value;
      cout << "DelCommand: key= " << command.key << "\n";

    } else {
      cerr << "Error length";
      return;
    }
  } else {
    cerr << "Unknown command";
    return;
  }
  // for (Token i : parseT) {
  //   cout << i.value << "\n";
  // }
}

int main() {
  string input = "GET age";
  vector<Token> parseT = tokenize(input); // make the vector of tokens
  parseToken(parseT);
  return 0;
}
