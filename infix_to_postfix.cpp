#include<iostream>

using namespace std;

class Infix_To_Postfix{

    public:
        bool is_empty(){
            if(top == -1){
                return true;
            } else {
                return false;
            }
        }
        void push(char value){

            top++;
            stack_replica[top] = value;
        } 
        char pop(){
            char to_pop = this->stack_replica[top];
            top--;
            return to_pop;


        } 
        void priority() {

            if ( ( letter == '*' ||letter =='/' ) && (stack_replica [top] == '*' || stack_replica[top] =='/') ){

                    while (1)
                    {
                        if( stack_replica[top] == '+' || stack_replica[top] == '-' )
                        {
                            break;
                        }else if( stack_replica[top] == '(' ){
                            pop();
                            break ;
                        }else if( is_empty()){
                            break;
                        }
                        else{
                            cout<<pop();
                        }
                    }
                    push(letter);
            }else if ( (letter == '+' || letter == '-') && (stack_replica[top]== '-' || stack_replica[top]== '+') ){

                    while(1){
                        if( stack_replica[top] == '(' )
                        {
                            pop();
                            break;
                        }
                        else if(is_empty()) {
                            break;
                        }
                        else {
                            cout<<pop();
                        }    
                        
                    }
                    push(letter);
            }else if( (letter == '/' || letter== '*')&& (stack_replica[top]== '-' || stack_replica[top]== '+')) {
                push(letter);
            }
            else if ( (letter == '-' || letter == '+')&&( stack_replica[top] = '/' ||stack_replica[top] == '*') ){
                while(1){
                    if( stack_replica[top] == '(' )
                        {
                            pop();
                            break;
                        }else if( is_empty()){
                            break;
                        }else{
                            cout<<pop();
                        }
                }
            }
            else if((letter == '(')&& (stack_replica[top]=='*'||stack_replica[top]=='/'||stack_replica[top]=='+'||stack_replica[top]=='-')) {
                push(letter);
            }
            else if( ( letter == '+' || letter == '-' || letter == '/' || letter== '*') &&( stack_replica[top] == '(') ) {
                push(letter);
            }
            else if ( letter == ')'){
                push(letter);
                pop();
                while(1){
                    if( stack_replica[top] == '(' )
                        {
                            pop();
                            break;
                        }else if(is_empty()){
                            break;
                        }else{
                            cout<<pop();
                        }
                }
            }

        } 
        int infix_to_postfix(){
            
        cin.getline(this->input, 500);   
            while (input [ counter ] != '\0') {
                if (input [ counter ] != white_space ) {
                    letter = input [ counter ]; 
                    if( letter == '(' || letter == ')'|| letter == '/' || letter == '-' || letter == '+'|| letter == '*' ) {
                        if(top == -1){
                            push(letter);
                        }else{
                        priority();
                        }
                    } else {
                        cout<< letter ; 
                    }
                }
                counter++;
            }
            while (1) {
                if(is_empty()){
                    break;
                }else {
                    cout<<pop();
                }
            }
            
            return 0;
        }
        
    private:

        int top = -1;
        char stack_replica[100];    
        char letter;
        char white_space = ' ';
        char input[500];
        int counter = 0;

};

int main(){
    Infix_To_Postfix obj;

    obj.infix_to_postfix();
    
    return 0;
}