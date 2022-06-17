#include <iostream>
#include <stack>
using namespace std;

/**
 * I: path = "/home/"
 * O: "/home"
 * Explanation: Note that there is no trailing slash after the last directory name.
 *
 * I: path = "/../"
 * O: "/"
 * Explanation: Going one level up from the root directory is a no-op,
 * as the root level is the highest level you can go.
 *
 * I: path = "/home//foo/"
 * O: "/home/foo"
 * Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
 */

string simplifyPath(string path);

int main(int argc, char const *argv[]) {
    string path = "/../abc//./def/";
    cout << simplifyPath(path) << endl;
    return 0;
}

// /../abc//./def/
// [abc, def]
// /abc/def
string simplifyPath(string path) {
    stack<string> fs;
    for (int i = 0; i < path.length(); i++) {
        if (path[i] == '/')
            continue;

        string tmp;
        while (path[i] != '/' && i < path.length()) {
            tmp += path[i];
            i++;
        }

        if (tmp == ".") {
            continue;
        } else if (tmp == "..") {
            if (!fs.empty()) {
                fs.pop();
            }
        } else {
            fs.push(tmp);
        }
    }

    if (fs.empty()) return "/";

    string ret;
    while (!fs.empty()) {
        ret = '/' + fs.top() + ret;
        fs.pop();
    }
    return ret;
}
