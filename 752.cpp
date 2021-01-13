#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Task {
    int index, arrival, time, serviced;
};

Task newTask(int index, int arrival, int time) {
    Task *t = new Task;
    t->index = index;
    t->arrival = arrival;
    t->time = time;
    return *t;
}

void bothtypes(vector<Task> &ptasks, vector<Task> &ntasks, int n);
void onetype(vector<Task> &tasks, int n);

int main(void) {
    int n;
    while (cin >> n) {
        vector<Task> ptasks, ntasks;
        for (int i = 0; i < n; i++) {
            int A, T, P;
            cin >> A >> T >> P;
            P == 0 ? ptasks.emplace_back(newTask(i, A, T)) : ntasks.emplace_back(newTask(i, A, T));
        }

        if (!ptasks.empty() && !ntasks.empty())
            bothtypes(ptasks, ntasks, n);
        else if (ptasks.empty())
            onetype(ntasks, n);
        else
            onetype(ptasks, n);
    }
}

void bothtypes(vector<Task> &ptasks, vector<Task> &ntasks, int n) {
    bool normFirst = ntasks.front().arrival < ptasks.front().arrival;
    int curtime = normFirst ? ntasks.front().arrival : ptasks.front().arrival;
    auto pit = ptasks.begin();
    auto nit = ntasks.begin();
    int i = 0;
    if (normFirst)
    {
        curtime += nit->time;
        nit->serviced = curtime;
        nit++, i++;
    }
    for (; i < n; i++)
    {
        if ((nit->arrival < pit->arrival && curtime < pit->arrival && nit != ntasks.end()) || pit == ptasks.end())
        {
            if (curtime < nit->arrival)
                curtime = nit->arrival;
            curtime += nit->time;
            nit->serviced = curtime;
            nit++;
        }
        else
        {
            if (curtime < pit->arrival)
                curtime = pit->arrival;
            curtime += pit->time;
            pit->serviced = curtime;
            pit++;
        }
    }
    map<int, int> orderOfTasks;
    for (int i = 0; i < ptasks.size(); i++)
        orderOfTasks[ptasks.at(i).index] = ptasks.at(i).serviced;
    for (int i = 0; i < ntasks.size(); i++)
        orderOfTasks[ntasks.at(i).index] = ntasks.at(i).serviced;
    auto it = orderOfTasks.begin();
    for (int i = 0; i < n - 1; i++, it++)
        cout << it->second << " ";
    cout << it->second << endl;
}

void onetype(vector<Task> &tasks, int n) {
    int curtime = 0;
    for (auto it = tasks.begin(); it != tasks.end(); it++) {
        if (curtime < it->arrival)
            curtime = it->arrival;
        curtime += it->time;
        it->serviced = curtime;
    }
    map<int, int> orderOfTasks;
    for (auto task : tasks)
        orderOfTasks[task.index] = task.serviced;
    auto it = orderOfTasks.begin();
    for (int i = 0; i < n - 1; i++, it++)
        cout << it->second << " ";
    cout << it->second << endl;
}