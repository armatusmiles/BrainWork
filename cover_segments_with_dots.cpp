#include <iostream>
#include <vector>
#include <list>

/** По данным nn отрезкам необходимо найти множество точек минимального размера,
    для которого каждый из отрезков содержит хотя бы одну из точек.
    В первой строке дано число 1≤n≤1001≤n≤100 отрезков.
    Каждая из последующих nn строк содержит по два числа 0≤l≤r≤1090≤l≤r≤109,
    задающих начало и конец отрезка. Выведите оптимальное число mm точек и сами mm точек.
    Если таких множеств точек несколько, выведите любое из них. **/


using Segment = std::pair<int, int>;

bool comp_func(const Segment& a, const Segment& b)
{
    if ( a.second == b.second )
        return a.first < b.first;
    return a.second < b.second;
}

std::vector <int> get_covering_set(std::list <Segment> segments) {

    std::vector<int> result;
    segments.sort(comp_func);

    while( segments.size() != 0)
    {
        result.push_back(segments.front().second);
        segments.pop_front();
        segments.remove_if([&](const Segment& s) { return s.second >= result.back() &&
                                                          s.first <= result.back();});
    }

    return result;
}

int main(void)
{
    int segments_count;
    std::cin >> segments_count;
    std::list <Segment> segments(segments_count);
    for (auto &s:segments) {
        std::cin >> s.first >> s.second;
    }

    auto points = get_covering_set(std::move(segments));
    std::cout << points.size() << std::endl;
    for (auto point:points) {
        std::cout << point << " ";
    }
    std::cout << std::endl;

}
