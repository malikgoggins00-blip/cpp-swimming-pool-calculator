#include <iostream>
using namespace std;

class SwimmingPool {
private:
    int length;
    int width;
    int depth;
    int current_water;

public:
    int fill_rate;
    int drain_rate;

    SwimmingPool(int length, int width, int depth, int fill_rate, int drain_rate) {
        this->length = length;
        this->width = width;
        this->depth = depth;
        this->fill_rate = fill_rate;
        this->drain_rate = drain_rate;
        this->current_water = 0;
    }

    int get_capacity() {
        return static_cast<int>(length * width * depth * 7.48);
    }

    int get_fill_time() {
        return fill_rate > 0 ? get_capacity() / fill_rate : 0;
    }

    int get_drain_time() {
        return drain_rate > 0 ? get_capacity() / drain_rate : 0;
    }

    int get_remaining_capacity() {
        return get_capacity() - current_water;
    }

    int get_time_to_fill() {
        return fill_rate > 0 ? get_remaining_capacity() / fill_rate : 0;
    }

    int get_time_to_drain() {
        return drain_rate > 0 ? current_water / drain_rate : 0;
    }

    void add_water(int time) {
        int water_to_add = fill_rate * time;

        if (current_water + water_to_add > get_capacity()) {
            current_water = get_capacity();
            cout << "Pool overflow prevented. Pool filled to maximum capacity." << endl;
        } else {
            current_water += water_to_add;
        }
    }

    void drain_water(int time) {
        int water_to_drain = drain_rate * time;

        if (current_water - water_to_drain < 0) {
            current_water = 0;
        } else {
            current_water -= water_to_drain;
        }
    }

    int get_current_water() {
        return current_water;
    }

    void set_current_water(int water) {
        if (water < 0) {
            current_water = 0;
        } else if (water > get_capacity()) {
            current_water = get_capacity();
        } else {
            current_water = water;
        }
    }
};

int main() {
    int length, width, depth, fill_rate, drain_rate;

    cout << "Pool data:" << endl;
    cout << "Length: ";
    cin >> length;
    cout << "Width: ";
    cin >> width;
    cout << "Depth: ";
    cin >> depth;
    cout << "Fill rate (gallons per minute): ";
    cin >> fill_rate;
    cout << "Drain rate (gallons per minute): ";
    cin >> drain_rate;

    SwimmingPool pool(length, width, depth, fill_rate, drain_rate);

    cout << "\nPool capacity: " << pool.get_capacity() << " gallons" << endl;
    cout << "Approximate fill time: " << pool.get_fill_time() << " minutes" << endl;
    cout << "Approximate drain time: " << pool.get_drain_time() << " minutes" << endl;

    return 0;
}
