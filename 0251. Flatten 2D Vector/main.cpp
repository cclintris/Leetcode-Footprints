#include <iostream>
#include <vector>
using namespace std;

class Vector2D {
   public:
    Vector2D(vector<vector<int>>& vec) {
        int m = vec.size();
        for (int i = 0; i < m; i++) {
            int n = vec[i].size();
            for (int j = 0; j < n; j++) {
                buffer.push_back(vec[i][j]);
            }
        }
        index = 0;
    }

    int next() {
        return buffer[index++];
    }

    bool hasNext() {
        return index >= buffer.size() ? false : true;
    }

   private:
    vector<int> buffer;
    int index;
};

int main(int argc, char const* argv[]) {
    return 0;
}
