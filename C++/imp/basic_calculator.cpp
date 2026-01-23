#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

class Solution {
 private:
  typedef enum { TOKEN_INT, TOKEN_OP } token_type;
  typedef union TokenValue {
    long val;
    char op;
  } token_value;

  typedef struct Token {
    token_type type;
    token_value data;
  } token;

  void add_to_tokens(std::vector<token>& tokens, token_type type, token_value val) {
    token t;
    t.type = type;
    t.data = val;
    tokens.push_back(t);
  }

  std::vector<token> get_tokens(const std::string& s) {
    std::vector<token> tokens;
    size_t start = 0;
    bool inNumber = false;

    for (size_t i = 0; i < s.size(); ++i) {
      char ch = s[i];

      switch (ch) {
        case ' ':
          if (inNumber) {
            token_value val{.val = std::stoll(s.substr(start, i - start))};
            add_to_tokens(tokens, TOKEN_INT, val);
            inNumber = false;
          }
          start = i + 1;
          break;

        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
          if (inNumber) {
            token_value val{.val = std::stoll(s.substr(start, i - start))};
            add_to_tokens(tokens, TOKEN_INT, val);
            inNumber = false;
          }

          add_to_tokens(tokens, TOKEN_OP, token_value{.op = ch});
          start = i + 1;
          break;

        default:
          if (isdigit(ch)) {
            if (!inNumber) {
              start = i;
              inNumber = true;
            }
          }
          break;
      }
    }

    if (inNumber) {
      token_value val{.val = std::stoll(s.substr(start))};
      add_to_tokens(tokens, TOKEN_INT, val);
    }

    return tokens;
  }

  std::pair<float, float> infix_binding_power(char op) {
    if (op == '+' || op == '-') return {1, 1.1};
    // if (op == '*' || op == '/')
    return {2, 2.1};
  }

  void print_tokens(const std::vector<token>& tokens) {
    for (const auto& t : tokens) {
      switch (t.type) {
        case TOKEN_INT:
          std::cout << "INT(" << t.data.val << ")";
          break;

        case TOKEN_OP:
          std::cout << "OP(" << t.data.op << ")";
          break;

        default:
          std::cout << "UNKNOWN";
          break;
      }
      std::cout << " ";
    }
    std::cout << "\n";
  }

  token operation(token& lhs, token& op, token& rhs) {
    switch (op.data.op) {
      case '+':
        return {TOKEN_INT, {.val = lhs.data.val + rhs.data.val}};
      case '-':
        return {TOKEN_INT, {.val = lhs.data.val - rhs.data.val}};
      case '*':
        return {TOKEN_INT, {.val = lhs.data.val * rhs.data.val}};
      case '/':
        return {TOKEN_INT, {.val = lhs.data.val / rhs.data.val}};
      default:
        throw std::runtime_error("Invalid operator");
    }
  }

  token prat_parser(std::vector<token>& tokens, float min_bp) {
    if (tokens.empty()) throw std::runtime_error("Unexpected end of input");

    // lhs
    token lhs = tokens.back();
    tokens.pop_back();

    if (lhs.type == TOKEN_INT) {
      // ok
    } else if (lhs.type == TOKEN_OP && lhs.data.op == '(') {
      lhs = prat_parser(tokens, 0);
      if (tokens.empty() || tokens.back().data.op != ')') throw std::runtime_error("Missing closing parenthesis");
      tokens.pop_back();  // consume ')'
    }
    // IMPORTANT: handle extra cases with better design probably do it in lexer i.e get_tokens func
    else if (lhs.type == TOKEN_OP && lhs.data.op == '-') {
      token rhs = prat_parser(tokens, 100);
      lhs = {TOKEN_INT, {.val = -rhs.data.val}};
    }

    while (!tokens.empty()) {
      token op = tokens.back();
      if (op.type != TOKEN_OP || op.data.op == ')') break;

      auto [lhs_bp, rhs_bp] = infix_binding_power(op.data.op);
      if (lhs_bp < min_bp) break;

      tokens.pop_back();
      token rhs = prat_parser(tokens, rhs_bp);
      lhs = operation(lhs, op, rhs);
    }

    return lhs;
  }

 public:
  int calculate(std::string s) {
    std::vector<token> tokens = get_tokens(s);
    // print_tokens(tokens);
    // std::cout << "\n";
    std::reverse(tokens.begin(), tokens.end());
    return prat_parser(tokens, 0).data.val;
  }
};

int main() {
  Solution sol;

  std::vector<std::string> tests = {"1 + 1", " 2-1 + 2 ", "(1+(4+5+2)-3)+(6+8)", "10 - (2 + 3)", "((7))"};

  for (const std::string& expr : tests) {
    int result = sol.calculate(expr);
    std::cout << "Expression: " << expr << " -> Result: " << result << "\n";
  }

  return 0;
}
