// HarryPorter.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;



string data_[8][20][20];

struct Result {//查询结果
	int book, chapter, line;
	string text;
};
void readfile(vector<string>  books_);

void display(string key, vector<string>  books_);

int main() {
	vector<string>  books_;
		books_.push_back("books\\J.K. Rowling - HP 0 - Harry Potter Prequel.txt");
		books_.push_back("books\\HP7--Harry_Potter_and_the_Deathly_Hallows_Book_7_.txt"),
		books_.push_back("books\\J.K. Rowling - HP 3 - Harry Potter and the Prisoner of Azkaban.txt"),
		books_.push_back("books\\HP2--Harry_Potter_and_the_Chamber_of_Secrets_Book_2_.txt"),
		books_.push_back("books\\J.K. Rowling - Quidditch Through the Ages.txt"),
		books_.push_back("books\\J.K. Rowling - The Tales of Beedle the Bard.txt"),
		books_.push_back("books\\J.K. Rowling - HP 6 - Harry Potter and the Half-Blood Prince.txt"),
		books_.push_back("books\\J.K. Rowling - HP 4 - Harry Potter and the Goblet of Fire.txt");


	string key;

	readfile(books_);//timer

	cin >> key;

	display(key, books_);//timer

	return 0;
}


void readfile(vector<string>  books_) {

	ifstream infile;
	int cur_book = 0,
		cur_chapter = 0,
		cur_line = 0;

	for (; cur_book<8; cur_book++) {
		infile.open(books_[cur_book].c_str());
		string s;
		while (getline(infile, s)) {
			if (strlen(s.c_str())>0 ) {
				if (strlen(s.c_str()) > 3) {
					//next line
					cur_line++;
					data_[cur_book][cur_chapter][cur_line] = s;
				}
				else {
				//next chapter
				cur_chapter++;
				cur_line = 0;
			}
			}
			
		}
	}
	return;
}


void display(string key, vector<string>  books_) {
	vector<Result> result;
	int result_num = 0;
	cout << "序号\t人名/地名\t页码\t章节\t书名\n";
	for (int cur_book = 0; cur_book<7; cur_book++) {
		for (int cur_chapter = 0; data_[cur_book][cur_chapter][0] != ""; cur_chapter++) {
			for (int cur_line = 0; data_[cur_book][cur_chapter][cur_line] != ""; cur_line++) {
				if (data_[cur_book][cur_chapter][cur_line].find(key) != string::npos) {
					Result tmp;
					result_num++;
					tmp.book = cur_book; tmp.chapter = cur_chapter; tmp.line = cur_line;
					tmp.text = data_[cur_book][cur_chapter][cur_line];
					result.push_back(tmp);
					cout << result_num << "\t" << key << "\t" << cur_chapter + 1 << "\t" << cur_line + 1 << "\t" << books_[cur_book] << endl;
				}
			}
		}
	}
	if (result_num > 0) {
		int index;
		cin >> index;
		cout << result[index - 1].text << endl;
	}
}