// HarryPorter.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;

struct Result {//查询结果
	int book, chapter, page;
	string text,pretext;
};

vector<string>  books_;

bool AllisNum(string s) {
	for (int i = 0; i < s.length(); i++) {
		int tmp = (int)s[i];
		if (tmp >= 48 && tmp <= 57) {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}

int main() {
	books_.push_back("books\\J.K. Rowling - HP 0 - Harry Potter Prequel.txt");
	books_.push_back("books\\HP7--Harry_Potter_and_the_Deathly_Hallows_Book_7_.txt");
	books_.push_back("books\\J.K. Rowling - HP 3 - Harry Potter and the Prisoner of Azkaban.txt");
	books_.push_back("books\\HP2--Harry_Potter_and_the_Chamber_of_Secrets_Book_2_.txt");
	books_.push_back("books\\J.K. Rowling - Quidditch Through the Ages.txt");
	books_.push_back("books\\J.K. Rowling - The Tales of Beedle the Bard.txt");
	books_.push_back("books\\J.K. Rowling - HP 6 - Harry Potter and the Half-Blood Prince.txt");
	books_.push_back("books\\J.K. Rowling - HP 4 - Harry Potter and the Goblet of Fire.txt");

	string key;
	cin >> key;

	vector<Result> result;

	string s;//use for search

	cout << "序号\t人/地名\t页码\t章节\t书名\n";

	for (int cur_book = 0; cur_book < books_.size(); cur_book++) {
		ifstream infile;
		infile.open(books_[cur_book].c_str());
		int cur_chapter = 0;
		int cur_page = 0;
		string pres = "";
		while (getline(infile, s)) {
			if (s.length() > 0) {//is a line
				if (s.find("Chapter") == 0 || s.find("CHAPTER") == 0) {//new chapter
					cur_chapter++;
				}
				else {
					if (AllisNum(s)) {//new page
						cur_page++;
					}
					else {
						if (s.find(key) != string::npos) {
							//just do it!!
							Result tmp;
							tmp.book = cur_book;
							tmp.chapter = cur_chapter;
							tmp.page = cur_page;
							tmp.text = s;
							tmp.pretext = pres;
							result.push_back(tmp);
							cout << result.size() << "\t" << key << "\t" << cur_page << "\t" << cur_chapter << "\t" << books_[cur_book] << endl;
						}
						pres = s;
					}
				}
			}
		} 
		infile.close();
	}
	int index;
	cin >> index;
	if (index > 0 && index <= result.size()) {
		cout << result[index - 1].pretext << endl << result[index - 1].text << endl;
	}
	getchar();
	return 0;
}
