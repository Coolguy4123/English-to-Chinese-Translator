#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <cctype>
using namespace std;

string process(unordered_map<string,string> &m,string sentence){
  string word;
  string temp = "";
  istringstream in(sentence);
  while(in >> word) {
    if(m.count(word)) {
    temp += m[word];
    }
    else {
    temp += word + " ";
    }
  }
  return temp;
  
}

string addp(unordered_map<string,string>&p, string sentence){
  string word;
  string temp="";
  istringstream in(sentence);
  while(in >> word){
    if(p.count(word)){
      temp+= p[word] + " ";
    }
    else {temp += '\''+ word + '\''+ " ";}
  }
  return temp;
}

void add_words(unordered_map<string,string>&m) {
  m["i"] = "我";
  m["am"] = "是";
  m["is"] = "是";
  m["you"] = "你";
  m["your"] = "你的";
  m["love"] = "愛";
  m["he"] = "他";
  m["she"] = "她";
  m["we"] = "我們";
  m["hi"] = "你好";
  m["hello"] = "你好";
  m["Hi"] = "你好";
  m["my"] = "我的";
  m["name"] = "名字";
  m["will"] = "會";
  m["if"] = "如果";
  m["have"] = "有";
  m["and"] = "和";
  m["a"] = "個";
  m["human"] = "人";
  m["friend"] = "朋友";
  m["are"] = "是";
  m["they"] = "他們";
  m["us"] = "我們";
  m["no"] = "不";
  m["not"] = "不是";
  
}

void add_pinyin(unordered_map<string,string>&p) {
  p["i"] = "wǒ";
  p["am"] = "shì";
  p["is"] = "shì";
  p["you"] = "nǐ";
  p["your"] = "nǐ de";
  p["love"] = "aì";
  p["he"] = "tā";
  p["she"] = "她";
  p["we"] = "我們";
  p["hi"] = "你好";
  p["hello"] = "你好";
  p["Hi"] = "你好";
  p["my"] = "我的";
  p["name"] = "名字";
  p["will"] = "會";
  p["if"] = "如果";
  p["have"] = "有";
  p["and"] = "和";
  p["a"] = "個";
  p["human"] = "人";
  p["friend"] = "朋友";
  p["are"] = "是";
  p["they"] = "他們";
  p["us"] = "我們";
  p["no"] = "不";
  p["not"] = "不是";
  
}
int main() {
  unordered_map<string,string>m,p;
  char choice;
  add_words(m);
  add_pinyin(p);
  bool repeat = true;

  
  cout << "Enter a sentence to be translated into Chinese. If have punchiations, please put spaces between it and the words, type 'ns' to stop program\n ";
  while(true){
    string sentence;
    cout << "Enter sentence:" << endl;
    getline(cin,sentence);
    string ans="",pinyin="";
    if(sentence == "ns"){
      break;
    }
  for(int i=0;i<sentence.size();i++) {
     sentence[i]=tolower(sentence[i]);
  }
  ans += process(m,sentence);
  pinyin += addp(p,sentence);
  cout << "Chinese Characters: " << ans << endl;
  cout << "Pinyin: " << pinyin << endl<<endl;
}
}