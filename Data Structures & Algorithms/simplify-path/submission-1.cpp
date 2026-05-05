class Solution {
public:
    string simplifyPath(string path) {
        stack<string>file;
        int len = path.size();
        int currIndex =  0;
        while(currIndex < len){
            while(path[currIndex] == '/'){
                currIndex++;
            }
            cout << path[currIndex] << endl;
            string fileName = "";
            while(path[currIndex] != '/' && currIndex < len){
                fileName += path[currIndex];
                currIndex++;
            }
            if(fileName == ".." && !file.empty()){
                file.pop();
            }else if(fileName == ".." && file.empty() || fileName == "" ||fileName == "."){
                continue;
            }else{
                file.push(fileName);
            }
        } 
        if(file.empty()){
            return "/";
        }
        string ans = "";
        while(!file.empty()){
            string newDir = "";
            newDir += "/";
            newDir += file.top();
            // cout << newDir << endl;
            ans = newDir + ans; 
            file.pop();
        }
        return ans;
    }
};
/* /_home/a */