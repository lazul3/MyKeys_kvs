#include <iostream>
#include <vector>

using namespace std;

vector<string> tokenize(string input) {
  vector<string> tokens;
  string aux = "";
  if (input.empty()){
      cout << "Empty string";
  }
  for (char c : input) {
    if (c == ' '|| c=='\n' || c== '\t') {
      if (!aux.empty()) {
        tokens.push_back(aux);
        aux = "";
      }

    } else {
      aux = aux + c;
    }
  }
  if (!aux.empty()){
      tokens.push_back(aux);
  }
  return tokens;
}
int main() {
  string input = "";
  vector<string> parseT = tokenize(input);
  for (string i : parseT) {
    cout << i << "\n";
  }
  return 0;
}
