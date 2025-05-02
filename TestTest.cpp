#include <iostream>
#include <deque>
#include <string>

using namespace std;
struct Printjob {
    int ID;
    string doc_name;
    bool priority;
};

deque<Printjob> printque;

void add_job(const Printjob& job) {
    if (job.priority) {
        printque.push_front(job);
        cout << "Priority job: " << job.doc_name << endl;
    }
    else {
        printque.push_back(job);
        cout << "Non priority job:" << job.doc_name << endl;
    }
}

void next_job() {
    if (!printque.empty()) {
        Printjob job = printque.front();
        printque.pop_front();
        cout << "ID: " << job.ID << job.doc_name << endl;
    }
    else {
        cout << "Queue is empty" << endl;
    }
}

void print_content() {
    if (printque.empty()) {
        cout << "Queue is empty" << endl;
    }
    else {
        for (const auto& job : printque) {
            cout << "[ID:" << job.ID << "] "
                 << job.doc_name << " "
                 << (job.priority ? "Prio" : "No Prio")
                 << endl;
        }
    }
}