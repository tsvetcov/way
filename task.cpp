#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

//template <class T>
class vertex {
private:
	int id;
public:
	int getId() {
		return id;
	}
	vertex(int _id);
	bool operator<(vertex a) const {
		return (id < a.getId());
	}
};

vertex::vertex(int _id) :
	id(_id)
{}

class edge {
public:
	vertex start, finish;
	double weight;
	edge(int s, int f);
};

edge::edge(int s, int f) :
	start(s)
	, finish(f)
{
	weight = 1;

}

class Graph {
public:
	Graph(int m, int countV);
	int coun();
private:
	std::map < vertex, std::map<vertex, edge>> gr;
};

Graph::Graph(int m, int countV) {
	int temp, y;
	map<vertex, edge> t;
	for (int i = 0; i < countV; ++i) {
		gr[vertex(i)] = t;
	}
	for (int i = 0; i < m; ++i) {
		//cout << endl;
		for (int j = 0; j < countV; ++j) {
			std::cin >> temp >> y;
			//cout << temp;

			gr[vertex(temp - 1)].insert(make_pair(vertex(y - 1), edge(temp - 1, y - 1)));
			gr[vertex(y - 1)].insert(make_pair(vertex(temp - 1), edge(y - 1, temp - 1)));

		}
	}
}
int Graph::coun() {
	int r = 0;
	for (auto i = gr.begin(); i != gr.end(); ++i) {
		auto y = i->first;
		cout << gr[y].size() << " ";
		//cout << gr[y].size();
	}
	return 0;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	Graph g(m, n);
	int w = g.coun();
	//std::cout << w / 2;
	return 0;
}