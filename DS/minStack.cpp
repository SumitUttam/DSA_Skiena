#include<bits/stdc++.h> 

class minStack {
private:
    std::stack< std::pair<int,int> > stack;

public:
    int top (){
        return this->stack.top().first;
    }

    void push(int x){
        if (stack.empty())
            stack.push({x,x});

        else 
            stack.push({x, std::min(stack.top().second, x)});
    }

    void pop(){
        this->stack.pop();
    }

    int findMin (){
        return stack.top().second;
    }
};

int main(){
    minStack s;
    s.push(5);
    s.push(6);
    s.push(3);

    std::cout<<s.findMin()<<std::endl;

    s.pop();

    std::cout<<s.findMin()<<std::endl;

    return 0;
}

