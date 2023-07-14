#include <iostream>
// I have used my own vector
class Vector
{
    int capacity;
    double *memory;
    int elements;
public:

    Vector():capacity(10), elements(0), memory(new double [capacity]){};
    //this is for knowing is my vector growing normally;
    int getCapacity();

    void push_back(double _x){
        if(elements >= capacity)
        {
            int newCapacity = capacity*2;
            double *temp = new double [newCapacity];


            for(int i =0; i< elements; i++)
            {
                temp[i] = memory[i];
            }

            delete [] memory;
            memory = temp;
            capacity = newCapacity;

        }

        memory[elements] = _x;
        elements++;
    };
    bool empty(){
        if(elements == 0)
        {
            return true;
        }

        return false;
    };
    void pop_back(){if(elements > 0) {elements-=1;}};
    int back(){
        if(elements > 0)
            return memory[elements-1];
    };
    ~Vector(){
        delete [] memory;
        };
    int size(){
        return elements;
    };
    double &operator[](int x)
    {
        return memory[x];
    }


};

int Vector::getCapacity() {return capacity;};
void display_view();
double addition(Vector &v1);


int main() {
    Vector v1;
    double result = 0;
    double number;
    char choice;
    bool exit_calculator = false;
    bool add = false;

    do {
        double num2;
        display_view();
        std::cin >> choice;
        if(choice != '=') {
            std::cout << "Enter the operation number: \n";
            std::cin >> number;
        }

        switch (choice) {
            case '+':
                v1.push_back(number);
                result = addition(v1);
                add = true;
                break;

            case '-':
                std::cout << "Enter the number to subtract: ";
                std::cin >> number;
                if (!v1.empty() && add == true) {
                    result = addition(v1) - number;
                }
                result = result - number;

                break;


            case '/' :

                if(add == true) {
                    result = addition(v1) / number;
                }
                else {
                    double num2;
                    do {

                    } while (num2 == 0);


                    result = number / num2;
                }
                break;

            case '*' :
                if(add == true)
                {
                    result = result * number;
                }
                else
                {
                    std::cout << "Enter the number that you multiply: ";
                    std::cin >> num2;
                    result = number * num2;
                }




            case '=':
                std::cout << "Result is " << result << std::endl;
                break;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }

        if(choice == '=') {
            std::cout << "Do you want to continue? (Y/N): ";
            std::cin >> choice;
            if (choice == 'N' || choice == 'n') {
                exit_calculator = true;
            }
        }



    } while (!exit_calculator);




}
void display_view() {

    std::cout << "-------------------------------------" << std::endl
              << "For Addition: write this + " << std::endl
              << "For Subtraction: write this - " << std::endl
              << "For Multiplication: write this  * " << std::endl
              << "For Division: write this / " << std::endl
              << "For Result of Operation: write this = "<<std::endl
              << "------------------------------------- \n" << std::endl
              << "Enter your choice ";


}


double addition(Vector &v1) {
    double result = 0;

    for (int i = 0; i < v1.size(); i++) {
        result += v1[i];

    }
    return result;
}

// This is other method of multiplication methods for my algorithm
/* int result = 0;
     std::string input;
     while(true)
     {
         std::cout<<"Enter the number that you wwant add "<<std::endl;
         std::cin>>input;

         if(input == "calculate")
         {
             break;
         }

         int number = std::stoi(input); //stoi is a changing the string to integer
         result+=number;
     }
     std::cout<<"result is "<<result<<std::endl;
      return 0;
      */