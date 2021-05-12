#include <iostream>
#include <string>
#include <fstream>
#include <vector>


using namespace std;

void ft_tokens(string str, vector <string> &token)
{
  for(int i = 0; i < str.size(); ++i)
  {
    if((str[i] != ' ' && str[i] != '\t') && (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0' || str[i + 1] == '\n'))  
   // if(((str[i] <= 'z' && str[i] >= 'a') || (str[i] <= 'Z' && str[i] >= 'A')) && (!(str[i + 1] != ' ' && str[i + 1] != '\t') || (str[i + 1] == '\0' || str[i + 1] == '\n')))
      token.push_back("Unexpected");
    else if(str[i] == ' ')
      token.push_back("Indent");
    else if(str[i] == '\t')
      token.push_back("Tab");
  }
  token.push_back("\\n");
}

int main(void)
{
  string line, line2_0;
  vector <string> token(0);
  ifstream file("text.txt");
  if(file.is_open())
  {
    while(getline(file, line))
    {
      ft_tokens(line, token);
    }
  }
  for(int i = 0; i < token.size(); ++i)
    cout << token[i] << ' ';
  cout << endl;
  file.close();
  cout << "Poka" << endl;
  return 0;
}
