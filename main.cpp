#include <iostream>
#include <stdlib.h>
#include <string>

#define pagesTotal 200

using std::cout;
using std::to_string;
using std::string;

void concatenateURL(string *pURL, int page);
void downloadPage(string URL, int page);
void convertToPdf();
void deleteAllJPGs();
string getAllPagesString();

int main() {

  string URL = "", *pURL = &URL;
  int page;

  for (page = 1; page <= pagesTotal; page++) {
    concatenateURL(pURL, page);
    downloadPage(URL, page);
  }

  cout << "\nConverting...";
  convertToPdf();

  cout << "Deleting residual files...\n";
  deleteAllJPGs();

  return 0;
}

void concatenateURL(string *pURL, int page) {

  string urlPath1 = "https://img.yumpu.com/62283426/";
  string urlPath2 = "/1215x1600/composicion-escrita.jpg";

  *pURL = urlPath1 + to_string(page) + urlPath2;

}

string getAllPagesString() {
  string allPagesSeparatedBySpaces = "";

  for (int page = 1; page <= pagesTotal; page++) {
    string filename = "page" + to_string(page) + ".jpg";

    allPagesSeparatedBySpaces += filename + " "; 
  }

  return allPagesSeparatedBySpaces;
}

void downloadPage(string URL, int page) {

  string filename = "page" + to_string(page) + ".jpg";

  system("clear || cls");

  cout << "=== Downloading page " << page << " as " << filename << " ===" << std::endl;

  string concatenatedCommand = "curl " + URL + " --output " + filename; 
  system(concatenatedCommand.c_str());

}

void convertToPdf() {

  string concatenatedCommand = "convert " + getAllPagesString() + " composicion-escrita.pdf";

  system(concatenatedCommand.c_str());
  
}

void deleteAllJPGs() {
  string concatenatedCommand = "rm " + getAllPagesString();

  system(concatenatedCommand.c_str());
}
