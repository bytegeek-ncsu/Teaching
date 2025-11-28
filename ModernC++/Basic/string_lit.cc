#include<iostream>
#include<string>

using namespace std;
using namespace std::literals;

int main(){

    const char* string_stream{"Hey I love you"};

    cout<<"Const char ptr:"<<string_stream<<endl;

    string literal{"Hello I like you"s};
    cout<<literal<<endl;

    cout<<"Hello"s+"world"s<<endl;

    // String literal with escaped characters
    //Here we \ to put "  to put \ you need again escape char '\'
	string url = "<a href=\"file\">C:\\\"Program Files\"\\</a>\\n";
	cout << "URL is " << url << endl << endl;

    //to make the above one easier use Raw string 

    string raw_url = R"(<a href="file">C:\"Program Files"\</a>\n)";
    cout<<raw_url<<endl;
    // but if you parentheisis in your string it is a trouble again
    //so use delimiter option like this. x is the delimitter

    string delimited_url = R"x(<a href="file">C:\"Program Files (x86)"\</a>\n)x";
	cout << "Delimited URL is " << delimited_url << endl << endl;

    return 0;
}