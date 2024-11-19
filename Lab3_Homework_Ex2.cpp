/*
MSSV: 22520772
Full name: Nguyen Thi Huyen Linh
Lab3 - Homework - Exercise 2
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct ResearchPaper
{
    string title;
    string abstract;
    string authors;
    vector<string> keywords;
};

class SearchEngine
{
private:
    vector<ResearchPaper> papers;

    string toLower(string str)
    {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }
public:
    void addPaper(const ResearchPaper& paper)
    {
        papers.push_back(paper);
    }

    vector<ResearchPaper> search(string& query)
    {
        vector<ResearchPaper> results;
        query = toLower(query);
        for(const auto& paper : papers)
        {
            for(const auto& keyword : paper.keywords)
            {
                if (toLower(keyword).find(query) != string::npos)
                {
                    results.push_back(paper);
                    break;
                }
            }
        }
        return results;
    }

};

int main() {
    SearchEngine engine;
    engine.addPaper({"Deep Learning for NLP", "An overview of deep learning techniques for natural language processing.", "Alice Smith, Bob Johnson", {"deep learning", "NLP", "neural networks"}});
    engine.addPaper({"Quantum Computing Advances", "Recent advances in quantum computing and its applications.", "Carol White, David Brown", {"quantum computing", "quantum algorithms", "entanglement"}});
    engine.addPaper({"Blockchain Technology", "The impact of blockchain technology on various industries.", "Eve Black, Frank Green", {"blockchain", "cryptocurrency", "decentralization"}});
    engine.addPaper({"Quantum Machine Learning", "Exploring the intersection of quantum computing and machine learning.", "Grace Lee, Henry Kim", {"quantum computing", "machine learning", "quantum algorithms"}});
    engine.addPaper({"Applications of Quantum Computing", "Various applications of quantum computing in different fields.", "Ivy Park, Jack Wilson", {"quantum computing", "applications", "quantum algorithms"}});

    string query;
    cout << "Enter search query: ";
    getline(cin, query);

    vector<ResearchPaper> results = engine.search(query);

    cout << "Search Results:\n";
    for(const auto& paper : results)
    {
        cout << "Title: " << paper.title << "\nAbstract: " << paper.abstract << "\nAuthors: " << paper.authors << "\nKeywords: ";
        for (const auto& keyword : paper.keywords)
        {
            cout << keyword << " ";
        }
        cout << "\n\n";
    }

    return 0;
}
