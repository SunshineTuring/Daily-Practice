#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;
#define Num_thread 5


int main(void) {
	vector<thread> threads;
	mutex t;
	for (int i = 0; i < Num_thread; i++) {
		threads.push_back(thread([&t]() {
			
			//t.lock();
			lock_guard<mutex> gurad(t);
			cout << "hello from lamda threa" << this_thread::get_id() << endl;
			//t.unlock();
		}));
	}
	for (auto &thread_ : threads) {
		thread_.join();
	}
	cout << "main thread" << "\t" << this_thread::get_id() << endl;
	int a = 2;
	int b = 3;
	(a > b)?a:(void)1;
	return 0;
}