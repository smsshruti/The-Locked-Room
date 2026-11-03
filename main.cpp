# include <iostream> 
# include <string> 
#include <cstdlib> 
#include <ctime> 
#include <cmath>
# include <limits>
#include <cctype>

using namespace std; 

void playMathsMode();
void playPuzzleMode();
void offerModeSwitch();

// Function to display the story and introduces the player to the locked room

void intro() 
{ 
    cout<<"\n\nSorry... You should not have done that." 
        << "\n\n The Evil Puzzle Master has locked you inside a dangerous room." 
        <<"\n\n There is no turning back now."<<endl; 
    cout<<"\n\n Press Enter to continue"<<endl; 
    cin.get();  
} 
 
void poster() 
{ 
     cout<<"As you look around, you notice a poster. Something is written on it." 
        <<"\nYou must read the statements written on the poster if you want to escape from the room."<<endl; 
    cout<<"\n\nPress Enter to see the statements written on the poster"<<endl;     
    cin.get(); 
} 
 
void welcome() 
{ 
     cout<<"\n+---------------------------------------------------------------------------------------------+"<<endl; 
    cout<<"|                            Welcome to The Locked Room!                                      |"<<endl; 
    cout<<"+---------------------------------------------------------------------------------------------+"<<endl; 
    cout<<"\n Now that you are here..." 
        << "\n The only way to get out of this room is through that locked door." 
        << "\n To unlock the door..." 
        << "\n You must discover a five-character code." 
        << "\n The code follows the following pattern:" 
        << "\n\n[SPECIAL CHAR][DIGIT][ALPHA][DIGIT][ALPHA]" 
        << "\n\n You will face different questions and challenges to discover each character." 
        <<"\n Answer every question carefully and remember your answer." 
        <<" \n Your answer- whether words or numbers - may help you discover the code." 
        <<"\n Solve the challenge..." 
        <<"\n Find all five characters..." 
        <<"\n Unlock the room..." 
        <<"\n Good luck..."<<endl; 
    cout<<"\n\nPress Enter to continue"<<endl; 
    cin.get(); 
} 
 
void box() 
{ 
    cout<<"As you finish reading the previous statements, a box suddenly falls down near your feet." 
        <<"\nWritten on the outside of the box:" 
        <<"\n'Something Very Important For You'" 
        <<"\nAs you open the box, you find something you did not expect..."<<endl; 
    cout<<"\n\nPress Enter to find out what you found."<<endl; 
    cin.get(); 
 
    cout<<"\nA strange object lies inside." 
        <<"\nThe moment you touch it, it suddenly transforms." 
        <<"\nThe object activates and connects to your locker." 
        <<"\nAs you look at its screen, you begin to feel nervous..." 
        <<"\nSomething tells you that you are about to make an important choice."<<endl; 
    cout<<"\n\n Press Enter to find out what is written on the screen"<<endl; 
    cin.get(); 
 
    cout<<"\n\nActually, nothing is written on the screen." 
        <<"\nHowever, as you press Enter, a message suddenly appears..." 
        <<"\n\nNow you are connected to the locker in the room... " 
        <<"\n\nKeep the rules in mind and answer carefully..."<<endl; 
    cout<<"\n\nPress Enter to continue"<<endl; 
    cin.get(); 
}

// Function to store a generated question and its correct numerical answer
struct SpecialQuestion 
{ 
    string question; 
    long  long answer; 
};
 
// To store already generated Maths Mode questions so that they are not repeated next time
const int MAX_MATHS_QUESTIONS = 500;
string usedMathsQuestions[MAX_MATHS_QUESTIONS];
int usedMathsQuestionCount = 0;

// Check if a generated question is new or already used 
bool isNewMathsQuestion(SpecialQuestion question)
{
    string signature = question.question + "|" + to_string(question.answer);

    for (int i = 0; i < usedMathsQuestionCount; i++)
    {
        if (usedMathsQuestions[i] == signature)
            return false;
    }

    if (usedMathsQuestionCount < MAX_MATHS_QUESTIONS)
    {
        usedMathsQuestions[usedMathsQuestionCount] = signature;
        usedMathsQuestionCount++;
    }

    return true;
}

// Function to get a valid choice from user
int getValidChoice(int numberOfOptions)
{
    int choice;

    while(true)
    {
        if(cin >> choice)
        {
            if(choice >= 1 && choice <= numberOfOptions)
            {
                return choice;
            }
        }

        cout << "Invalid choice! Please enter a number from 1 to "
             << numberOfOptions << ": ";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Accepts valid integer input reject text
long long getValidNumber()
{
    long long number;

    while (true)
    {
        if (cin >> number)
        {
            return number;
        }

        cout << "Invalid input! Please enter a valid number: ";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Accepts valid numerical input including decimal values
double getValidDouble()
{
    double number;

    while (true)
    {
        if (cin >> number)
        {
            return number;
        }

        cout << "Invalid input! Please enter a valid number: ";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Display generated special character options included one correct option
void showSpecialOptions(char options[]) 
{ 
    cout<<"\nChoose a special character from the options given below." 
        <<"\nOne of them may be the first character of your code." 
        <<"\n 1."<<options[0] 
        <<"\n 2."<<options[1] 
        <<"\n 3."<<options[2] 
        <<"\n 4."<<options[3] 
        <<"\n 5."<<options[4] 
        <<endl; 
} 
 
// To display code progress after unlocking special character code
void showCodeProgress(char specialCharacter) 
{ 
    cout<<"\nCorrect!"<<endl; 
 
    cout<<"\n\n Code Progress: " 
        << specialCharacter <<" _ _ _ _"<<endl; 
}

// To display code progress after unlocking two character code
void showDigitProgress(char specialCharacter, int digit)
{
    cout<<"\nCorrect!"<<endl;

    cout<<"\n\nCode Progress: "
        << specialCharacter <<" "<< digit << " _ _ _" <<endl;
}

// To display code progress after unlocking three character code
void showAlphaProgress(char specialCharacter, int digit, char alphaCharacter)
{
    cout << "\nCode Progress: "
        << specialCharacter << " "
        << digit << " "
        << alphaCharacter << " _ _\n";
}

// To display code progress after unlocking four character code
void showDigit2Progress(char specialCharacter, int digit, char alphaCharacter, int digit2)
{
    cout<<"\nCorrect!"<<endl;

    cout<<"\n\nCode Progress: "<< specialCharacter << " " << digit << " " << alphaCharacter <<" "
        << digit2 << " _" <<endl;
}

// Returns the character selected by user from available options
char getSelectedCharacter(int specialChoice, char options[]) 
{ 
    if( specialChoice < 1 || specialChoice > 5 )
       return '\0';

    return options[specialChoice - 1]; 
} 

// Function to check whether number is prime or not 
bool isPrime(int number) 
{ 
    if(number < 2) 
        return false; 
 
    for(int i = 2; i <= number / 2; i++) 
    { 
        if(number % i == 0) 
            return false; 
    } 
 
    return true; 
} 
 
// Used to find the nth prime number
int nthPrime(int n) 
{ 
    int count = 0; 
    int number = 1; 
    while(count < n) 
    { 
        if(isPrime(number)) 
        { 
           count++; 
        } 
        number++; 
    } 
    return number - 1; 
} 

// Make a number into single digit by adding its digits repeatedly until a single digit 
int reduceToSingleDigit(double number) 
{ 
    number = fabs(number);
 
    while(number >= 10) 
    { 
        double sum = 0; 
 
        while(number >= 1) 
        { 
            double digit = fmod(number,10); 
            sum += digit;
            number = floor(number/10);
        } 
 
        number = sum; 
    } 
    return static_cast<int>(number); 
}

//Function to generate four unique digit option must include the correct answer as a single digit
void generateDigitOptions(int options[], int correctDigit)
{
    options[0] = correctDigit;

    int count = 1;

    while (count < 4)
    {
        int randomDigit = rand() % 10;

        bool alreadyPresent = false;

        for (int i = 0; i < count; i++)
        {
            if (options[i] == randomDigit)
            {
                alreadyPresent = true;
                break;
            }
        }

        if (!alreadyPresent)
        {
            options[count] = randomDigit;
            count++;
        }
    }

    for (int i = 3; i > 0; i--)
    {
        int randomIndex = rand() % (i + 1);

        int temp = options[i];
        options[i] = options[randomIndex];
        options[randomIndex] = temp;
    }
}

// To display all four generated options included correct digit as one of the options
void showDigitOptions(int options[])
{
    cout << "\nChoose the correct answer:"
         << "\n1. " << options[0]
         << "\n2. " << options[1]
         << "\n3. " << options[2]
         << "\n4. " << options[3]
         << endl;
}

// Change number to its corresponding alphabet character
char getAlphabetCharacter(int number)
{
    return 'A' + number - 1;
}

// Function to relate digit from 0-9 to special character 
char getKeyboardCharacter(int number) 
{ 
    switch(number) 
    { 
        case 1: return '!'; 
        case 2: return '@'; 
        case 3: return '#'; 
        case 4: return '$'; 
        case 5: return '%'; 
        case 6: return '^'; 
        case 7: return '&'; 
        case 8: return '*'; 
        case 9: return '('; 
        case 0: return ')'; 
    } 
 
    return '?'; 
} 

// Function to generate five special character options must include correct special character in this 
void generateSpecialOptions(char options[], char correctCharacter) 
{ 
    char specialCharacters[] = 
    { 
        '!', '@', '#', '$', '%', 
        '^', '&', '*', '(', ')' 
    }; 
 
    options[0] = correctCharacter; 
 
    int count = 1; 
 
    while(count < 5) 
    { 
        int randomIndex = rand() % 10; 
        char randomCharacter = specialCharacters[randomIndex]; 
 
        bool alreadyPresent = false; 
 
        for(int i = 0; i < count; i++) 
        { 
            if(options[i] == randomCharacter) 
            { 
                alreadyPresent = true; 
                break; 
            } 
        } 
 
        if(!alreadyPresent) 
        { 
            options[count] = randomCharacter; 
            count++; 
        } 
    } 
 
    for(int i = 4; i > 0; i--) 
    { 
        int randomIndex = rand() % (i + 1); 
 
        char temp = options[i]; 
        options[i] = options[randomIndex]; 
        options[randomIndex] = temp; 
    } 
} 
 
// Function to generate question on basis of this pattern during special character challenge in first attempt
SpecialQuestion generateQ1() 
{ 
    int primePosition = rand() % 10 + 1; 
    int selectedPrime = nthPrime(primePosition); 
 
    int secondPrimePosition = rand() % 10 + 1; 
    int secondPrime = nthPrime(secondPrimePosition); 
 
    char operation; 
    int operationChoice = rand() % 4; 
 
    int aChoice = rand() % 4;

    int A;
    string aQuestion;

    if(aChoice == 0)
    {
        A = 4 + 2;
        aQuestion = "A = smallest composite number + only even prime";
    }
    else if(aChoice == 1)
    {
        int aPrimePosition = rand() % 10 + 1;
        int aPrime = nthPrime(aPrimePosition);

        A = aPrime + 4;

        aQuestion = "A = " + to_string(aPrimePosition)
            + "th smallest prime + smallest composite number";
    }
    else if(aChoice == 2)
    {
        int aPrimePosition = rand() % 10 + 1;
        int aPrime = nthPrime(aPrimePosition);

        A = aPrime * 2;

        aQuestion = "A = twice the "
            + to_string(aPrimePosition)
            + "th smallest prime";
    }
    else
    {
        int aPrimePosition = rand() % 10 + 1;
        int aPrime = nthPrime(aPrimePosition);

        A = 4 * 2 + aPrime;

        aQuestion = "A = 4 * 2 + "
            + to_string(aPrimePosition)
            + "th smallest prime";
    } 

    int B = 2 * selectedPrime - secondPrime; 
    int answer; 
     
    if(operationChoice == 0) 
        operation = '+'; 
    else if(operationChoice == 1) 
        operation = '-'; 
    else if(operationChoice == 2) 
        operation = '*'; 
    else 
        operation = '/'; 
     
    if(operation == '+') 
    { 
       answer = A + B; 
    } 
    else if(operation == '-') 
    { 
       answer = A - B; 
    } 
    else if(operation == '*') 
    { 
       answer = A * B; 
    } 
    else 
    { 
        while(B == 0 || A % B != 0) 
        { 
            primePosition = rand() % 10 + 1;
            selectedPrime = nthPrime(primePosition);

            secondPrimePosition = rand() % 10 + 1;
            secondPrime = nthPrime(secondPrimePosition); 
            
            B = 2 * selectedPrime - secondPrime; 
        } 
 
        answer = A / B; 
    } 
 
    string operationPart(1, operation); 
 
    string primePart = to_string(primePosition) + "th smallest prime"; 
    string secondPrimePart = to_string(secondPrimePosition) + "th smallest prime"; 
 
    string bQuestion = "B = twice " + primePart + " - " + secondPrimePart; 
 
    SpecialQuestion q; 
 
    q.question = aQuestion +"\n"; 
    q.question += bQuestion + "\n"; 
    q.question += "Find A " + operationPart + " B"; 
 
    q.answer = answer; 
 
    return q; 
} 

// To find the nth largest and nth smallest number used in genearting question for pattern 2 
int nthLargest(int largest, int n)
{
    return largest - n + 1;
}
int nthSmallest(int smallest, int n)
{
    return smallest + n - 1;
}

// Generate question on basis of this pattern during special charcter challenge in second attempt
SpecialQuestion generateQ2() 
{ 
    int n = rand() % 100 + 1;
    int number = nthLargest(999, n);
    
    int secondn= rand() % 100 +1;
    int secondNumber = nthSmallest(100, secondn);

    char operation;
    int operationChoice = rand() % 2;
    int aChoice = rand() % 2;
    int A;
    string aQuestion;
    if(aChoice==0)
    {
        int an= rand() % 100 + 1;
        int aNumber = nthLargest(999, an);
        
        A = aNumber;
        aQuestion = "A = " + to_string(an) + "th largest three-digit number";
    }
    else
    {
        int an= rand() % 100 + 1;
        int aNumber = nthSmallest(100, an);
        
        A = aNumber;
        aQuestion = "A = " + to_string(an) + "th smallest three-digit number";
    }
    int B = number + secondNumber;
    int answer;
    if(operationChoice == 0)
    {
        operation = '+';
        answer = A + B;
    }
    else 
    {
        operation = '-';
        answer = A - B;
    }
    string operationPart(1, operation); 
 
    string numberPart = to_string(n) + "th largest three-digit number"; 
    string secondNumberPart = to_string(secondn) + "th smallest three-digit number"; 
 
    string bQuestion = "B =  " + numberPart + " + " + secondNumberPart; 
 
    SpecialQuestion q; 
 
    q.question = aQuestion +"\n"; 
    q.question += bQuestion + "\n"; 
    q.question += "Find A " + operationPart + " B"; 
 
    q.answer = answer; 
 
    return q; 

}

// Genertae question of missing pattern based for first digit challenge  
SpecialQuestion generateQ3()
{
    int start = rand() % 9 - 4;
    int n = start;
    int sequence[7];

    int operationChoice = rand() % 3;

    for (int i = 0; i < 7; ++i)
    {
        int term;

        if (operationChoice == 0)
        {
            term = n * n * n + (n + 1);
        }
        else if (operationChoice== 1)
        {
            term = n * n * n - (n + 1);
        }
        else
        {
            term = n * n * n * (n + 1);
        }
        sequence[i] = term;
        ++n;
    }

    int missingIndex = rand() % 7;
    int answer = sequence[missingIndex];
    string question = "";

    for (int i = 0; i < 7; ++i)
    {
        if (i == missingIndex)
        {
            question += "______";
        }
        else
        {
            question += to_string(sequence[i]);
        }
        if (i < 6)
        {
            question += ", ";
        }
    }
    return {question, answer};
}

// Generate a missing number sequence for the first alphabet challenge 
SpecialQuestion generateAlphaQuestion()
{
    long long terms[7];

    // Randomly selects one operation(additon, subtraction, multiplication, division) for the entire sequence
    int operation = rand() % 3;

    for (int i = 0; i < 7; i++)
    {
        // Generate seven terms using n values from -1 to 5 
        int n = i - 1;

        long long base = 2 * n - 1;
        long long power = 1;

        // Calculate (2n - 1)^(n + 1)
        for (int p = 0; p < n + 1; p++)
        {
            power *= base;
        }

        if (operation == 0)
            terms[i] = power + n;
        else if (operation == 1)
            terms[i] = power - n;
        else
            terms[i] = power * n;
    }

    // Choose the missing term from one of the first five position (indices 0 to 4)
    int missingIndex = rand() % 5;

    string question = "Find the missing number: ";

    for (int i = 0; i < 7; i++)
    {
        if (i == missingIndex)
            question += "__";
        else
            question += to_string(terms[i]);

        if (i < 6)
            question += ", ";
    }

    SpecialQuestion q;
    q.question = question;
    q.answer = terms[missingIndex];

    return q;
}

// Convert a number into an alphabet character using modulu 26    
char getAlphabetCharacter(long long number)
{
    if (number < 0)
        number = -number;

    int letterIndex = number % 26;

    if (letterIndex == 0)
        letterIndex = 26;

    return 'A' + letterIndex - 1;
}

// Generate four unique alphabet options, including the correct answer 
void generateAlphaOptions(char options[], char correctLetter)
{
    options[0] = correctLetter;

    for (int i = 1; i < 4; i++)
    {
        char letter;
        bool duplicate;

        do
        {
            letter = 'A' + rand() % 26;
            duplicate = false;

            for (int j = 0; j < i; j++)
            {
                if (options[j] == letter)
                {
                    duplicate = true;
                    break;
                }
            }
        }
        while (duplicate);

        options[i] = letter;
    }

    for (int i = 0; i < 4; i++)
    {
        int j = rand() % 4;
        char temp = options[i];
        options[i] = options[j];
        options[j] = temp;
    }
}

// Display all four generated alphabet options
void showAlphaOptions(char options[])
{
    for (int i = 0; i < 4; i++)
    {
        cout << i + 1 << ". " << options[i] << endl;
    }
}

// To generate 12 random numbers between 1 and 100 for arithmetic operations
void generateArithmeticNumbers(int numbers[])
{
    for (int i = 0; i < 12; i++)
    {
        numbers[i] = rand() % 100 + 1;
    }
}

// To generate 11 random arithmetic operators for opeartions between 12 numbers 
void generateArithmeticOperators(char operators[])
{
    char availableOperators[4] = {'+', '-', '*', '/'};

    // Ensure all four operations appear
    for (int i = 0; i < 4; i++)
    {
        operators[i] = availableOperators[i];
    }

    // Fill the remaining seven positions randomly
    for (int i = 4; i < 11; i++)
    {
        operators[i] = availableOperators[rand() % 4];
    }

    // Shuffle all eleven operators
    for (int i = 10; i > 0; i--)
    {
        int j = rand() % (i + 1);

        char temp = operators[i];
        operators[i] = operators[j];
        operators[j] = temp;
    }
}

// Display the arithmetic expression
void showArithmeticExpression(int numbers[], char operators[])
{
    for (int i = 0; i < 12; i++)
    {
        cout << numbers[i];

        if (i < 11)
            cout << " " << operators[i] << " ";
    }

    cout << endl;
}

// Calculate the answer of arithmeric expression using BODMAS rule
double calculateArithmeticAnswer(int numbers[], char operators[])
{
    // 'term' handles multilplication and division , while 'total' stores accumulated result 
    double total = 0;
    double term = numbers[0];
    char sign = '+';

    for (int i = 0; i < 11; i++)
    {
        // Perform multiplication and division immediately to give them higher precedence
        if (operators[i] == '*')
        {
            term = term * numbers[i + 1];
        }
        else if (operators[i] == '/')
        {
            term = term / numbers[i + 1];
        }
        else
        {
            // Complete the current term using previous sign, then start a new term
            if (sign == '+')
            {
                total += term;
            }
            else
            {
                total -= term;
            }

            term = numbers[i + 1];
            sign = operators[i];
        }
    }

    // Add or subtracted the last term because the loop has ended
    if (sign == '+')
    {
        total += term;
    }
    else
    {
        total -= term;
    }

    return total;
}

// To check if answer is finite and an integer 
bool isValidAnswer(double answer)
{
    if (!isfinite(answer))
       return false;

    if ( floor(answer) != answer )
       return false;   

    return true;
}

// Stores an alphabet riddle question and its correct alphabet answer
struct AlphaRiddle
{
    string question;
    char answer;
};

// Check if generated alphabet riddle question is new or already used
bool isNewMathsQuestion(AlphaRiddle question)
{
    string signature = question.question + "|" + question.answer;

    for (int i = 0; i < usedMathsQuestionCount; i++)
    {
        if (usedMathsQuestions[i] == signature)
            return false;
    }

    if (usedMathsQuestionCount < MAX_MATHS_QUESTIONS)
    {
        usedMathsQuestions[usedMathsQuestionCount] = signature;
        usedMathsQuestionCount++;
    }

    return true;
}

// Generates an arithmetic riddle whose solution defines an alphabet character 
AlphaRiddle generateAlphaRiddle()
{
    int secretNumber = rand() % 26 + 1;
    char operators[4] = { '+', '-', '*', '/'};

    // Shuffle the four operations
    for(int i = 3; i>0; i--)
    {
        int j = rand() % (i+1);

        char temp = operators[i];
        operators[i] = operators[j];
        operators[j] = temp;
    }
     
    int numbers[4];
    long long result = 0;
    bool validExpression = false;

    //Generate numbvers until division is exact 
    while (!validExpression)
    {
        for(int i = 0; i<4 ; i++)
        {
            numbers[i] = rand() % 9 + 1;
        }

        long long total = 0;
        long long term = secretNumber;
        char sign = '+';

        validExpression = true;

        // Calculate using BODMAS 
        for (int i = 0; i<4; i++)
         {
            if(operators[i] == '*')
            {
                term = term * numbers[i];
            }
            else if (operators[i] == '/')
            {
                if (term % numbers[i] != 0)
                {
                    validExpression = false;
                    break;
                }
                term = term/numbers[i];
            }
            else
            {
                if (sign == '+')
                    total = total + term;
                else
                    total = total - term;
                
                term = numbers[i];
                sign = operators[i];  
            }
         }
         if (validExpression) 
         {
            if (sign == '+')
                total = total + term;
            else 
                total = total - term;
                
            result = total;    
         }
    }
    AlphaRiddle riddle;
    
    riddle.answer = getAlphabetCharacter(secretNumber);
    riddle.question = "Solve X";

    for (int i = 0; i<4; i++)
    {
        riddle.question += " ";
        riddle.question += operators[i];
        riddle.question += " ";
        riddle.question += to_string(numbers[i]);
    }
    riddle.question += "=";
    riddle.question += to_string(result);
    riddle.question += "\nChoose an alphabet to unlock the code";

    return riddle;
}

// Global variables to check if each challenge is solved and saves those characters for code progress display

bool specialSolved = false;
char savedSpecialCharacter = ' ';

bool digitSolved = false;
int savedDigit = -1;

bool alphaNumberSolved = false;
char savedAlphaCharacter = ' ';

bool digit2Solved = false;
int savedDigit2 = -1;

bool alpha2Solved = false;
char savedAlpha2 = ' ';

// MATHS MODE STARTS HERE
void playMathsMode()
{
    cout<<"You chose to solve by maths mode..."<<endl;  
    
    // SPECIAL CHARACTER CHALLENGE STARTS HERE

    if(!specialSolved)
    {
        SpecialQuestion question1;

        do
        {
            question1 = generateQ1();
        }
        while (!isNewMathsQuestion(question1));
 
        cout<<"\n A keyboard is more than just a collection of keys."<<endl; 

        cout<<"\n-------------------   SPECIAL CHARACTER CHALLENGE   ---------------------"<<endl;
 
        cout<<"\n\nQuestion:" 
            <<"\n"<<question1.question<<endl; 
 
        long long ans;
        cout<<"\n\nEnter your answer:";
        ans = getValidNumber();
 
        if(ans==question1.answer) 
        { 
            int singleDigit = reduceToSingleDigit(question1.answer); 
 
            char correctCharacter = getKeyboardCharacter(singleDigit); 
                
            char options[5]; 
 
            generateSpecialOptions(options, correctCharacter);  
 
            showSpecialOptions(options); 
 
            int specialChoice; 
 
            cout << "\n Enter your choice: "; 
            specialChoice = getValidChoice(5);
 
            char selectedCharacter = getSelectedCharacter(specialChoice, options); 
                 
            if(selectedCharacter == correctCharacter) 
            {    
                showCodeProgress(correctCharacter);
                savedSpecialCharacter = correctCharacter;
                specialSolved = true;
            }     
            else 
            { 
                cout << "\nYou failed!"<<endl;
                offerModeSwitch();
                return; 
            } 
        }         
        else  
        { 
            cout<<"\nWrong answer!" 
               <<"\nYou have remaining one attempt only." 
               <<"\nAnswer carefully..."<<endl; 
                     
            SpecialQuestion chanceQuestion;

            do
            {
                chanceQuestion = generateQ2();
            }
            while (!isNewMathsQuestion(chanceQuestion));

            cout<<"\n\nQuestion:" 
               <<"\n"<<chanceQuestion.question<<endl;
 
            long long ans;
            cout<<"\n\nEnter your answer:";
            ans = getValidNumber();   
 
            if(ans==chanceQuestion.answer)
            {
                int singleDigit = reduceToSingleDigit(chanceQuestion.answer);

                char correctCharacter = getKeyboardCharacter(singleDigit);

                char options[5];

                generateSpecialOptions(options, correctCharacter);

                showSpecialOptions(options);

                int specialChoice;

                cout<<"\n Enter your choice: ";
                specialChoice = getValidChoice(5);

                char selectedCharacter = getSelectedCharacter(specialChoice, options);

                if(selectedCharacter == correctCharacter)
                {
                    showCodeProgress(correctCharacter);
                    savedSpecialCharacter = correctCharacter;
                    specialSolved = true;
                }    
                else
                {
                    cout <<"You failed!"<<endl;
                    offerModeSwitch();
                    return;
                } 
            }
            else
            {
                cout<<"\nBoth attempts failed!"<<endl;
                offerModeSwitch();
                return;
            }
        }
    }    

    // DIGIT CHALLENGE STARTS HERE 
            
    if (specialSolved && !digitSolved)
    {
        cout<<"\nYou are good at addition....lets see how well you handle numbers."<<endl;
        
        cout<<"\n-------------------   DIGIT CHALLENGE   -------------------\n"<<endl;

        while(!digitSolved)
        {
            SpecialQuestion q3;

            do
            {
                q3 = generateQ3();
            }
            while (!isNewMathsQuestion(q3));

            cout<<"\nQuestion: "<< q3.question << endl;

            for (int attempt = 1; attempt <= 2; ++attempt)
            {
                long long digitAnswer;
                cout<<"\n\nEnter your answer:";
                digitAnswer = getValidNumber();

                if (digitAnswer == q3.answer)
                {
                    cout<<"\nCorrect! You found the missing number."<<endl;
                        
                    savedDigit = reduceToSingleDigit(q3.answer);
                        
                    int options[4];
                    generateDigitOptions(options, savedDigit);
                    showDigitOptions(options);

                    int digitChoice;
                    cout<<"\n\nEnter your choice (1-4):";
                    digitChoice = getValidChoice(4);

                    if (digitChoice >= 1 && digitChoice <= 4 && options[digitChoice - 1] == savedDigit)
                    {
                        showDigitProgress(savedSpecialCharacter, savedDigit);
                        digitSolved = true;
                    }
                    else
                    {
                        cout << "\nWrong choice! The secret remains locked." << endl;
                        offerModeSwitch();
                        return;
                    }
                    break;    
                }
                else
                {
                    cout << "\nWrong answer!" << endl;

                    if (attempt == 1)
                        cout << "You have one attempt remaining. Try again." << endl;
                    
                    else
                    {
                        cout << "\nBoth attempts failed." << endl;
                        offerModeSwitch();
                        return;
                    }
                }
            }    
        }
    }
            
    // ALPHABET CHALLENGE STARTS HERE
            
    if (specialSolved && digitSolved && !alphaNumberSolved)
    {
        cout<<"\n\n In division, what remains may mean nothing --- or reveal everything.\n\n"<<endl;
         
        cout<<"-----------------   ALPHABET CHALLENGE   ----------------\n"<<endl;

        while (!alphaNumberSolved)
        {
            SpecialQuestion alphaQuestion;

            do
            {
                alphaQuestion = generateAlphaQuestion();
            } 
            while (!isNewMathsQuestion(alphaQuestion));

            cout << alphaQuestion.question << endl;

            for (int attempt = 1; attempt <= 2; attempt++)
            {
                long long playerAnswer;
                cout<<"\n\nEnter your answer:";
                playerAnswer = getValidNumber();

                if (playerAnswer == alphaQuestion.answer)
                {
                    char correctLetter = getAlphabetCharacter(alphaQuestion.answer);

                    cout << "\nCorrect! Now find the letter.\n";
                    cout << "\nYour letter is hidden among these options:\n";

                    char alphaOptions[4];
                    generateAlphaOptions(alphaOptions, correctLetter);
                    showAlphaOptions(alphaOptions);
                            
                    int alphaChoice;
                    cout << "Choose your letter (1-4): ";
                    alphaChoice = getValidChoice(4);

                    if (alphaChoice >= 1 && alphaChoice <= 4)
                    {
                        savedAlphaCharacter = getSelectedCharacter(alphaChoice, alphaOptions);

                        if ( savedAlphaCharacter == correctLetter)
                        {
                            cout << "Correct letter!\n";

                            showAlphaProgress(savedSpecialCharacter, savedDigit, savedAlphaCharacter);
                            alphaNumberSolved = true;
                        }
                        else
                        {
                            cout << "Wrong letter!\n";
                            offerModeSwitch();
                            return;
                        }    
                    }
                    else
                        cout << "Invalid choice!\n";

                    break;
                }
                else
                {
                    cout << "\nWrong answer!" << endl;

                    if (attempt == 1)
                        cout << "You have one attempt remaining. Try again." << endl;
                    
                    else
                    {
                        cout << "\nBoth attempts failed." << endl;
                        offerModeSwitch();
                        return;
                    }
                }
            }
        }
    }
            
    // DIGIT CHALLENGE START HERE

    if (specialSolved && digitSolved && alphaNumberSolved && !digit2Solved)
    {
        bool arithmeticSolved = false;
        double answer;

        cout<<"\n\n------------------   DIGIT CHALLENGE   ------------------"<<endl;

        while(!arithmeticSolved)
        {
            int numbers[12];
            char operators[11];

            do
            {
                generateArithmeticNumbers(numbers);
                generateArithmeticOperators(operators);

                answer = calculateArithmeticAnswer(numbers, operators);

            } while (!isValidAnswer(answer));

            cout << "\n\nArithmetic Challenge!\n";

            showArithmeticExpression(numbers, operators);
            
            for ( int attempt = 1; attempt<=2; attempt++ )
            {
                double playerAnswer;
                cout << "\nEnter your answer: ";
                playerAnswer = getValidDouble();

                if (playerAnswer == answer)
                {
                    cout << "Correct!" << endl;
                    arithmeticSolved = true;

                    break;
                }
                else
                {
                    cout << "Incorrect!" << endl;

                    if (attempt == 1)
                        cout << "You have one attempt remaining. Try again!" << endl;
                    else
                    {
                        cout<<"Both attempts failed."<<endl;
                        offerModeSwitch();
                        return;
                    }
                }  
            }
        }    
                
        int singleDigitAnswer = reduceToSingleDigit(answer);

        long long digitInput;

        do
        {
            cout << "\nSelect the single-digit number (0-9) to unlock the digit code: ";
            digitInput = getValidNumber();

            if (digitInput < 0 || digitInput > 9)
                cout << "Please enter a digit between 0 and 9." << endl;

        } while (digitInput < 0 || digitInput > 9);

        savedDigit2 = static_cast<int>(digitInput);

        if(savedDigit2 == singleDigitAnswer)
        {
            cout<<"Digit Code Unlocked!"<<endl;

            showDigit2Progress(savedSpecialCharacter, savedDigit, savedAlphaCharacter, savedDigit2);
            digit2Solved = true;
        }
        else
        {
            cout<<"Incorrect! Digit code remains locked."<<endl;
            offerModeSwitch();
            return;
        }
    }    

    // FINAL ALPHABET CHALLENGE STARTS HERE
    
    if (specialSolved && digitSolved && alphaNumberSolved && digit2Solved)
    {
        cout<<"\n\n---------------   ALPHABET CHALLENGE   -------------\n"<<endl;

        while(!alpha2Solved)
        {            
            int finalChoice;

            for (int attempt = 1; attempt <= 2; attempt++)
            {
                AlphaRiddle finalQuestion;

                do
                {
                    finalQuestion = generateAlphaRiddle();
                }
                while (!isNewMathsQuestion(finalQuestion));

                cout << "\n\nAlphabet Challenge.\n";
                cout << finalQuestion.question << endl;

                char finalOptions[4];

                generateAlphaOptions(finalOptions, finalQuestion.answer);

                cout << "\nChoose the correct alphabet:\n";
                showAlphaOptions(finalOptions);

                cout << "\nEnter your choice (1-4): ";
                finalChoice = getValidChoice(4);

                savedAlpha2 = finalOptions[finalChoice - 1];

                if (savedAlpha2 == finalQuestion.answer)
                {
                    alpha2Solved = true;

                    cout << "\n***************************************\n";
                    cout << "       CONGRATULATIONS!\n";
                    cout << "      YOU SOLVED THE CODE!\n";
                    cout << "****************************************\n";

                    cout << "\n\nYour final code is: "<<savedSpecialCharacter<<" "<<savedDigit<<" "
                        <<savedAlphaCharacter<<" "<<savedDigit2<<" "<<savedAlpha2 << endl;

                    cout << "\n\nYou have successfully unlocked the room!\n";

                    break;
                }
                else
                {
                    cout << "\nWrong alphabet!\n";

                    if (attempt == 1)
                        cout << "You have one attempt remaining. Try again!\n";
                    
                    else
                    {
                        cout << "\nBoth attempts failed." << endl;
                        offerModeSwitch();
                        return;
                    }
                }
            }
        }
    }
}

// PUZZLE MODE FUNCTIONS HERE

void offerModeSwitch()
{
    cout << "\nChoose another way to proceed:\n";
    cout << "1. Try Maths Mode\n";
    cout << "2. Try Puzzle Mode\n";

    int choice = getValidChoice(2);

    if (choice == 1)
        playMathsMode();

    else
        playPuzzleMode();
}

// Stores the sequence of digits, mssing digit and its position
struct SpecialPattern
{
    int digits[7];
    int missingDigit;
    int missingPosition; 
};

// Generate a random digit from 0 to 9
int generateStartingDigit()
{
    return rand() % 10;
}

// Randomly selects a direction in which digit sequence progresses 
int generateDirection()
{
    return (rand() % 2 == 0) ? 1 : -1;
}

// Generate a sequence of 7 digits using random starting digit and direction then randomly select one missing position
SpecialPattern generatePattern()
{
    SpecialPattern pattern;

    int digit = generateStartingDigit();
    int direction = generateDirection();

    // Each successive digit moves an increasing number of positions (1, 2, 3...) in the selected direction
    for (int i = 0; i < 7; i++)
    {
        pattern.digits[i] = digit;

        if (i < 6)
        {
            int position = (digit == 0) ? 9 : digit - 1;

            position = (position + direction * (i + 1) + 100) % 10;

            digit = (position == 9) ? 0 : position + 1;
        }
    }

    pattern.missingPosition = rand() % 7;
    pattern.missingDigit = pattern.digits[pattern.missingPosition];

    return pattern;
}

// Display special character sequence with one character hidden
void displayPattern(SpecialPattern pattern)
{
    cout<<"\n\n===============    SPECIAL CHARACTER CHALLENGE    ==============="<<endl;
    cout << "\nThe sequence follows a pattern. Find it and guess the missing symbol!\n\n";

    for (int i = 0; i < 7; i++)
    {
        if (i == pattern.missingPosition)
        {
            cout << " __ ";
        }
        else
        {
            cout << getKeyboardCharacter(pattern.digits[i]);
        }
        if (i < 6)
        {
            cout<<"  ,  ";
        }
    }

    cout << "\n";
}

// Take the player guess for missing exactly one special character 
char getPlayerGuess()
{
    string guess;

    cout << "\nEnter the missing symbol: ";

    while (true)
    {
        cin >> guess;

        if (guess.length() == 1)
            return guess[0];

        cout << "Please enter only one symbol: ";
    }
}

// Check whether player's guesses symbol matches the missing symbol
bool checkPatternAnswer(SpecialPattern pattern, char guess)
{
    char correctAnswer = getKeyboardCharacter(pattern.missingDigit);

    if (guess == correctAnswer)
    {
        cout << "\nCorrect! You solved the pattern!\n";
        return true;
    }
    else
    {
        cout << "\nWrong answer!"<<endl;
        return false;
    }
}

// Stores the riddle and hidden number used in first digit challenge
struct DigitPuzzle
{
    string riddle;
    int hiddenNumber;
};

bool checkDigitAnswer(DigitPuzzle puzzle, long long guess);
int calculateDigitCode(int number);

// Extracts the digits of a number and stores them in an array from right to left like digits[0] stores the ones digit,
//digits[1] the tens digit, and digits[2] the hundreds digit
void extractDigits(int number, int digits[])
{
    int index = 0;

    while (number > 0)
    {
        digits[index] = number % 10;
        number = number / 10;
        index++;
    }
}

// Generate a random two digit or three diggit number
int generateHiddenNumber()
{
    int numberLength = rand() % 2;

    if (numberLength == 0)
        return 10 + rand() % 90;
    else
        return 100 + rand() % 900;
}

// Count the digits in a given number
int countDigits(int number)
{
    int count = 0;

    while (number > 0)
    {
        number = number / 10;
        count++;
    }

    return count;
}

// To create clues about hidden number using its digit sum, and their product 
string generateDigitRiddle(int number)
{
    int digits[3] = {0, 0, 0};

    extractDigits(number, digits);

    int length = countDigits(number);

    string riddle;

    if (length == 2)
    {
        int ones = digits[0];
        int tens = digits[1];

        riddle = "I am a two-digit number.\n";

        if (tens > ones)
            riddle += "My tens digit is " + to_string(tens - ones) + " greater than my ones digit.\n";

        else if (ones > tens)
            riddle += "My ones digit is " + to_string(ones - tens) + " greater than my tens digit.\n";

        else
            riddle += "My two digits are equal.\n";

        riddle += "The sum of my digits is " + to_string(tens + ones) + ".\n";

        riddle += "The product of my digits is " + to_string(tens * ones) + ".\n";
    }
    else
    {
        int ones = digits[0];
        int tens = digits[1];
        int hundreds = digits[2];

        riddle = "I am a three-digit number.\n";

        riddle += "My hundreds and ones digits add up to " +
                  to_string(hundreds + ones) + ".\n";

        if (tens > ones)
            riddle += "My tens digit is " + to_string(tens - ones) + " greater than my ones digit.\n";

        else if (ones > tens)
            riddle += "My ones digit is " + to_string(ones - tens) + " greater than my tens digit.\n";
        else
            riddle += "My tens and ones digits are equal.\n";

        riddle += "The sum of all my digits is " + to_string(hundreds + tens + ones) + ".\n";

        riddle += "My tens digit multiplied by my ones digit is " + to_string(tens * ones) + ".\n";
    }

    return riddle;
}

// Generate a hidden number and create its corresponding riddle 
DigitPuzzle generateDigitPuzzle()
{
    DigitPuzzle puzzle;

    puzzle.hiddenNumber = generateHiddenNumber();

    puzzle.riddle = generateDigitRiddle(puzzle.hiddenNumber);

    return puzzle;
}

// Displays the generated riddle and asks the player to find the number
void displayDigitRiddle(DigitPuzzle puzzle)
{
    cout << "\n\n================    DIGIT CHALLENGE    ===============\n\n";
    cout << puzzle.riddle;
    cout << "\nFind me. Enter the number: ";
}

// Checks whether player's entered number matches hidden number 
bool checkDigitAnswer(DigitPuzzle puzzle, long long guess)
{
    if (guess == puzzle.hiddenNumber)
    {
        cout << "\nCorrect! You found me!\n";
        return true;
    }
    else
    {
        cout << "\nThat is not my number. Try again!\n";
        return false;
    }
}

// Multiplies the digit of hidden number and reduces it to single digit
int calculateDigitCode(int number)
{
    int product = 1;

    while (number > 0)
    {
        int digit = number % 10;
        product = product * digit;
        number = number / 10;
    }

    while (product >= 10)
    {
        int sum = 0;

        while (product > 0)
        {
            sum = sum + product % 10;
            product = product / 10;
        }

        product = sum;
    }

    return product;
}

//  FUNCTION FOR DIGTI CHALLENGE 
void playDigitPuzzle()
{   
    DigitPuzzle puzzle;

    int attempts = 0;
    bool solved = false;

    while (attempts < 2 && solved == false)
    {
        puzzle = generateDigitPuzzle();

        displayDigitRiddle(puzzle);

        long long guess;
        guess = getValidNumber();

        solved = checkDigitAnswer(puzzle, guess);

        attempts++;
    }

    if (solved == false)
    {
        offerModeSwitch();

        return;
    }

    int correctDigit = calculateDigitCode(puzzle.hiddenNumber);
    
    cout<<"\nNow multilply all the digits of your number..."
        <<"\nAdd the digits of product to get a single digit.. "
        <<"\n\nEnter the digit to unlock the code:";
    
    long long playerDigit;
    playerDigit = getValidNumber();

    if (playerDigit == correctDigit)
    {
        cout << "\nCorrect! You have unlocked the digit!\n";

        digitSolved = true;
        savedDigit = correctDigit;

        cout << "\nCode Progress: "
            << savedSpecialCharacter << " "
            << savedDigit << " _ _ _" << endl;
    }
    
    else
    {
        offerModeSwitch();
    }

}

// Stores the generated alphabet sequence and its missing letter
struct AlphaPuzzle
{
    string sequence;
    char missingLetter;
};

// Generate a random sequence of alphabet in which numerical pattern is hidden behind alphabet sequence
AlphaPuzzle generateAlphaPuzzle()
{
    AlphaPuzzle puzzle;

    int pattern = rand() % 3;
    int missingPosition = rand() % 5;

    int numbers[5];

    if (pattern == 0)
    {
        for (int i = 1; i <= 5; i++)
        {
            numbers[i - 1] = i * i * i;
        }
    }
    else if (pattern == 1)
    {
        for (int i = 1; i <= 5; i++)
        {
            numbers[i - 1] = i * (i + 1);
        }
    }
    else
    {
        for (int i = 1; i <= 5; i++)
        {
            numbers[i - 1] = i * (i + 1) * (i + 2);
        }
    }

    puzzle.sequence = " ";

    for (int i = 0; i < 5; i++)
    {
        char letter = getAlphabetCharacter(static_cast<long long>(numbers[i]));

        if (i == missingPosition)
        {
            puzzle.missingLetter = letter;
            puzzle.sequence += "__";
        }
        else
        {
            puzzle.sequence += letter;
        }

        if (i < 4)
        {
            puzzle.sequence += " , ";
        }
    }

    return puzzle;
}

// FUNCTION FOR ALPHABET PUZZLE 
void playAlphaPuzzle()
{
    int attempts = 0;
    bool passed = false;

    while (attempts < 2 && passed == false)
    {
        AlphaPuzzle puzzle = generateAlphaPuzzle();

        cout << "\n\n==============    ALPHA CHALLENGE    ==============\n";
        cout << "\nFind the pattern and enter the missing letter.";
        cout << "\n\n" << puzzle.sequence << "\n";

        string answerInput;
        char answer;

        cout << "\nEnter the missing letter: ";

        while (true)
        {
            cin >> answerInput;

            if (answerInput.length() == 1 && ((answerInput[0] >= 'A' && answerInput[0] <= 'Z') || (answerInput[0] >= 'a'
                 && answerInput[0] <= 'z')))
            {
                answer = toupper(answerInput[0]);
                break;
            }

            cout << "Please enter only one letter: ";
        }

        if (answer == puzzle.missingLetter)
        {
            cout << "\nCorrect! You solved the Alpha Challenge!";
            passed = true;
            alphaNumberSolved = true;
            savedAlphaCharacter = answer;

            cout << "\nCode Progress: "
                 << savedSpecialCharacter << " "
                 << savedDigit << " "
                 << savedAlphaCharacter << " _ _\n";
        }
        else
        {
            attempts++;
            cout << "\nIncorrect answer!";

            if (attempts < 2)
            {
                cout << "\nTry again with a new sequence.";
            }
        }
    }

    if (passed == false)
    {
        offerModeSwitch();
    }
}

// Three question categories used in digit 2 challenge 
const int MCQ = 1;
const int THIS_OR_THAT = 2;
const int WRITTEN_ANSWER = 3;

// Stores a personal question, its options, category, and answer-validation details
struct PersonalQuestion
{
    string question;
    string options[4];
    int correctOption;   // Stores correct option (1 -4)
    int type;           // Identifies the question category
    bool hasCorrectAnswer;   // Indicates whether question has a fixed correct answer
};

// Function declaartions for validating answer and calculating final digit
bool isPersonalAnswerValid(PersonalQuestion question, string answer);
int calculateDigit2(string firstAnswer, string secondAnswer);

// Stores question bank of 30 question for each category used in Digit Challenge 2
PersonalQuestion mcqQuestions[30];
PersonalQuestion thisOrThatQuestions[30];
PersonalQuestion writtenQuestions[30];

// Initialize the personal questions in form of MCQ, This-Or-That,  Written answer Questions 
void initializePersonalQuestions()
{
    // MCQ 1
    mcqQuestions[0].question = "Which of these is a citrus fruit?";
    mcqQuestions[0].options[0] = "Apple";
    mcqQuestions[0].options[1] = "Orange";
    mcqQuestions[0].options[2] = "Grape";
    mcqQuestions[0].options[3] = "Pear";
    mcqQuestions[0].correctOption = 2;
    mcqQuestions[0].type = MCQ;
    mcqQuestions[0].hasCorrectAnswer = true;

    // MCQ 2
    mcqQuestions[1].question = "Which would you choose for a relaxing evening?";
    mcqQuestions[1].options[0] = "Reading a book";
    mcqQuestions[1].options[1] = "Listening to music";
    mcqQuestions[1].options[2] = "Watching a movie";
    mcqQuestions[1].options[3] = "Playing a game";
    mcqQuestions[1].correctOption = 0;
    mcqQuestions[1].type = MCQ;
    mcqQuestions[1].hasCorrectAnswer = false;

    // MCQ 3
    mcqQuestions[2].question = "Which planet is known as the Red Planet?";
    mcqQuestions[2].options[0] = "Venus";
    mcqQuestions[2].options[1] = "Mars";
    mcqQuestions[2].options[2] = "Jupiter";
    mcqQuestions[2].options[3] = "Mercury";
    mcqQuestions[2].correctOption = 2;
    mcqQuestions[2].type = MCQ;
    mcqQuestions[2].hasCorrectAnswer = true;

    // MCQ 4
    mcqQuestions[3].question = "Which of these is a popular breakfast food?";
    mcqQuestions[3].options[0] = "Pancakes";
    mcqQuestions[3].options[1] = "Popcorn";
    mcqQuestions[3].options[2] = "Potato chips";
    mcqQuestions[3].options[3] = "Candy";
    mcqQuestions[3].correctOption = 1;
    mcqQuestions[3].type = MCQ;
    mcqQuestions[3].hasCorrectAnswer = true;

    // MCQ 5
    mcqQuestions[4].question = "Which type of weather do you enjoy most?";
    mcqQuestions[4].options[0] = "Sunny";
    mcqQuestions[4].options[1] = "Rainy";
    mcqQuestions[4].options[2] = "Cloudy";
    mcqQuestions[4].options[3] = "Snowy";
    mcqQuestions[4].correctOption = 0;
    mcqQuestions[4].type = MCQ;
    mcqQuestions[4].hasCorrectAnswer = false;

    // MCQ 6
    mcqQuestions[5].question = "How many sides does a hexagon have?";
    mcqQuestions[5].options[0] = "Five";
    mcqQuestions[5].options[1] = "Six";
    mcqQuestions[5].options[2] = "Seven";
    mcqQuestions[5].options[3] = "Eight";
    mcqQuestions[5].correctOption = 2;
    mcqQuestions[5].type = MCQ;
    mcqQuestions[5].hasCorrectAnswer = true;

    // MCQ 7
    mcqQuestions[6].question = "Which of these is a dairy product?";
    mcqQuestions[6].options[0] = "Butter";
    mcqQuestions[6].options[1] = "Rice";
    mcqQuestions[6].options[2] = "Lentils";
    mcqQuestions[6].options[3] = "Flour";
    mcqQuestions[6].correctOption = 1;
    mcqQuestions[6].type = MCQ; 
    mcqQuestions[6].hasCorrectAnswer = true;

    // MCQ 8
    mcqQuestions[7].question = "Which colour would you choose for your room?";
    mcqQuestions[7].options[0] = "Blue";
    mcqQuestions[7].options[1] = "Green";
    mcqQuestions[7].options[2] = "Purple";
    mcqQuestions[7].options[3] = "Yellow";
    mcqQuestions[7].correctOption = 0;
    mcqQuestions[7].type = MCQ;
    mcqQuestions[7].hasCorrectAnswer = false;

    // MCQ 9
    mcqQuestions[8].question = "Which instrument is used to measure temperature?";
    mcqQuestions[8].options[0] = "Barometer";
    mcqQuestions[8].options[1] = "Thermometer";
    mcqQuestions[8].options[2] = "Compass";
    mcqQuestions[8].options[3] = "Stopwatch";
    mcqQuestions[8].correctOption = 2;
    mcqQuestions[8].type = MCQ;
    mcqQuestions[8].hasCorrectAnswer = true;

    // MCQ 10
    mcqQuestions[9].question = "Which of these is traditionally made from cocoa beans?";
    mcqQuestions[9].options[0] = "Chocolate";
    mcqQuestions[9].options[1] = "Yogurt";
    mcqQuestions[9].options[2] = "Bread";
    mcqQuestions[9].options[3] = "Cheese";
    mcqQuestions[9].correctOption = 1;
    mcqQuestions[9].type = MCQ;
    mcqQuestions[9].hasCorrectAnswer = true;

    // MCQ Question 11
    mcqQuestions[10].question = "Which of these is commonly used to make French fries?";
    mcqQuestions[10].options[0] = "Potato";
    mcqQuestions[10].options[1] = "Cucumber";
    mcqQuestions[10].options[2] = "Apple";
    mcqQuestions[10].options[3] = "Carrot";
    mcqQuestions[10].correctOption = 1;
    mcqQuestions[10].type = MCQ;
    mcqQuestions[10].hasCorrectAnswer = true;

    // MCQ Question 12
    mcqQuestions[11].question = "Which is the largest ocean on Earth?";
    mcqQuestions[11].options[0] = "Atlantic Ocean";
    mcqQuestions[11].options[1] = "Indian Ocean";
    mcqQuestions[11].options[2] = "Pacific Ocean";
    mcqQuestions[11].options[3] = "Arctic Ocean";
    mcqQuestions[11].correctOption = 3;
    mcqQuestions[11].type = MCQ;
    mcqQuestions[11].hasCorrectAnswer = true;

    // MCQ Question 13
    mcqQuestions[12].question = "Which place would you most like to visit?";
    mcqQuestions[12].options[0] = "Mountains";
    mcqQuestions[12].options[1] = "Beach";
    mcqQuestions[12].options[2] = "Forest";
    mcqQuestions[12].options[3] = "Big city";
    mcqQuestions[12].correctOption = 0;
    mcqQuestions[12].type = MCQ;
    mcqQuestions[12].hasCorrectAnswer = false;

    // MCQ Question 14
    mcqQuestions[13].question = "Which of these is a popular frozen dessert?";
    mcqQuestions[13].options[0] = "Ice cream";
    mcqQuestions[13].options[1] = "Bread";
    mcqQuestions[13].options[2] = "Soup";
    mcqQuestions[13].options[3] = "Noodles";
    mcqQuestions[13].correctOption = 1;
    mcqQuestions[13].type = MCQ;
    mcqQuestions[13].hasCorrectAnswer = true;

    // MCQ Question 15
    mcqQuestions[14].question = "What is the square of 12?";
    mcqQuestions[14].options[0] = "124";
    mcqQuestions[14].options[1] = "132";
    mcqQuestions[14].options[2] = "144";
    mcqQuestions[14].options[3] = "154";
    mcqQuestions[14].correctOption = 3;
    mcqQuestions[14].type = MCQ;
    mcqQuestions[14].hasCorrectAnswer = true;

    // MCQ Question 16
    mcqQuestions[15].question = "Which activity would you choose on a free day?";
    mcqQuestions[15].options[0] = "Exploring somewhere new";
    mcqQuestions[15].options[1] = "Relaxing at home";
    mcqQuestions[15].options[2] = "Meeting friends";
    mcqQuestions[15].options[3] = "Learning a new skill";
    mcqQuestions[15].correctOption = 0;
    mcqQuestions[15].type = MCQ;
    mcqQuestions[15].hasCorrectAnswer = false;

    // MCQ Question 17
    mcqQuestions[16].question = "Which spice is commonly used to give food a yellow colour?";
    mcqQuestions[16].options[0] = "Turmeric";
    mcqQuestions[16].options[1] = "Black pepper";
    mcqQuestions[16].options[2] = "Cinnamon";
    mcqQuestions[16].options[3] = "Clove";
    mcqQuestions[16].correctOption = 1;
    mcqQuestions[16].type = MCQ;
    mcqQuestions[16].hasCorrectAnswer = true;

    // MCQ Question 18
    mcqQuestions[17].question = "Which gas do plants absorb during photosynthesis?";
    mcqQuestions[17].options[0] = "Oxygen";
    mcqQuestions[17].options[1] = "Carbon dioxide";
    mcqQuestions[17].options[2] = "Nitrogen";
    mcqQuestions[17].options[3] = "Hydrogen";
    mcqQuestions[17].correctOption = 2;
    mcqQuestions[17].type = MCQ;
    mcqQuestions[17].hasCorrectAnswer = true;

    // MCQ Question 19
    mcqQuestions[18].question = "Which would you rather receive as a gift?";
    mcqQuestions[18].options[0] = "A book";
    mcqQuestions[18].options[1] = "A game";
    mcqQuestions[18].options[2] = "A handmade item";
    mcqQuestions[18].options[3] = "An outing or experience";
    mcqQuestions[18].correctOption = 0;
    mcqQuestions[18].type = MCQ;
    mcqQuestions[18].hasCorrectAnswer = false;

    // MCQ Question 20
    mcqQuestions[19].question = "What is the next number in the sequence: 3, 6, 12, 24, __?";
    mcqQuestions[19].options[0] = "30";
    mcqQuestions[19].options[1] = "36";
    mcqQuestions[19].options[2] = "48";
    mcqQuestions[19].options[3] = "42";
    mcqQuestions[19].correctOption = 3;
    mcqQuestions[19].type = MCQ;
    mcqQuestions[19].hasCorrectAnswer = true;

    // MCQ Question 21
    mcqQuestions[20].question = "Which of these is commonly used to make popcorn?";
    mcqQuestions[20].options[0] = "Corn kernels";
    mcqQuestions[20].options[1] = "Rice grains";
    mcqQuestions[20].options[2] = "Wheat flour";
    mcqQuestions[20].options[3] = "Lentils";
    mcqQuestions[20].correctOption = 1;
    mcqQuestions[20].type = MCQ;
    mcqQuestions[20].hasCorrectAnswer = true;

    // MCQ Question 22
    mcqQuestions[21].question = "Which is the closest star to Earth?";
    mcqQuestions[21].options[0] = "Sirius";
    mcqQuestions[21].options[1] = "The Sun";
    mcqQuestions[21].options[2] = "Polaris";
    mcqQuestions[21].options[3] = "Alpha Centauri";
    mcqQuestions[21].correctOption = 2;
    mcqQuestions[21].type = MCQ;
    mcqQuestions[21].hasCorrectAnswer = true;

    // MCQ Question 23
    mcqQuestions[22].question = "Which would you choose for a creative activity?";
    mcqQuestions[22].options[0] = "Drawing or painting";
    mcqQuestions[22].options[1] = "Writing a story";
    mcqQuestions[22].options[2] = "Making music";
    mcqQuestions[22].options[3] = "Crafting something";
    mcqQuestions[22].correctOption = 0;
    mcqQuestions[22].type = MCQ;
    mcqQuestions[22].hasCorrectAnswer = false;

    // MCQ Question 24
    mcqQuestions[23].question = "Which of these is made by fermenting milk?";
    mcqQuestions[23].options[0] = "Yogurt";
    mcqQuestions[23].options[1] = "Lemonade";
    mcqQuestions[23].options[2] = "Apple juice";
    mcqQuestions[23].options[3] = "Coconut water";
    mcqQuestions[23].correctOption = 1;
    mcqQuestions[23].type = MCQ;
    mcqQuestions[23].hasCorrectAnswer = true;

    // MCQ Question 25
    mcqQuestions[24].question = "What is 15% of 200?";
    mcqQuestions[24].options[0] = "15";
    mcqQuestions[24].options[1] = "20";
    mcqQuestions[24].options[2] = "30";
    mcqQuestions[24].options[3] = "35";
    mcqQuestions[24].correctOption = 3;
    mcqQuestions[24].type = MCQ;
    mcqQuestions[24].hasCorrectAnswer = true;

    // MCQ Question 26
    mcqQuestions[25].question = "Which would you prefer for a weekend getaway?";
    mcqQuestions[25].options[0] = "An adventurous trip";
    mcqQuestions[25].options[1] = "A peaceful retreat";
    mcqQuestions[25].options[2] = "A city exploration";
    mcqQuestions[25].options[3] = "A stay at home";
    mcqQuestions[25].correctOption = 0;
    mcqQuestions[25].type = MCQ;
    mcqQuestions[25].hasCorrectAnswer = false;

    // MCQ Question 27
    mcqQuestions[26].question = "Which of these is a natural sweetener produced by bees?";
    mcqQuestions[26].options[0] = "Honey";
    mcqQuestions[26].options[1] = "Vinegar";
    mcqQuestions[26].options[2] = "Soy sauce";
    mcqQuestions[26].options[3] = "Mustard";
    mcqQuestions[26].correctOption = 1;
    mcqQuestions[26].type = MCQ;
    mcqQuestions[26].hasCorrectAnswer = true;

    // MCQ Question 28
    mcqQuestions[27].question = "Which number is a prime number?";
    mcqQuestions[27].options[0] = "21";
    mcqQuestions[27].options[1] = "27";
    mcqQuestions[27].options[2] = "29";
    mcqQuestions[27].options[3] = "33";
    mcqQuestions[27].correctOption = 3;
    mcqQuestions[27].type = MCQ;
    mcqQuestions[27].hasCorrectAnswer = true;

    // MCQ Question 29
    mcqQuestions[28].question = "Which superpower would you choose?";
    mcqQuestions[28].options[0] = "Flying";
    mcqQuestions[28].options[1] = "Becoming invisible";
    mcqQuestions[28].options[2] = "Reading minds";
    mcqQuestions[28].options[3] = "Teleportation";
    mcqQuestions[28].correctOption = 0;
    mcqQuestions[28].type = MCQ;
    mcqQuestions[28].hasCorrectAnswer = false;

    // MCQ Question 30
    mcqQuestions[29].question = "A clock shows 3:00. What is the angle between its hour and minute hands?";
    mcqQuestions[29].options[0] = "45 degrees";
    mcqQuestions[29].options[1] = "90 degrees";
    mcqQuestions[29].options[2] = "120 degrees";
    mcqQuestions[29].options[3] = "180 degrees";
    mcqQuestions[29].correctOption = 2;
    mcqQuestions[29].type = MCQ;
    mcqQuestions[29].hasCorrectAnswer = true;

    // This-or-That Question 1
    thisOrThatQuestions[0].question = "Which do you prefer?";
    thisOrThatQuestions[0].options[0] = "Sweet food";
    thisOrThatQuestions[0].options[1] = "Spicy food";
    thisOrThatQuestions[0].type = THIS_OR_THAT;
    thisOrThatQuestions[0].hasCorrectAnswer = false;

    // This-or-That Question 2
    thisOrThatQuestions[1].question = "Which do you prefer?";
    thisOrThatQuestions[1].options[0] = "Tea";
    thisOrThatQuestions[1].options[1] = "Coffee";
    thisOrThatQuestions[1].type = THIS_OR_THAT;
    thisOrThatQuestions[1].hasCorrectAnswer = false;

    // This-or-That Question 3
    thisOrThatQuestions[2].question = "Which do you prefer?";
    thisOrThatQuestions[2].options[0] = "Mango";
    thisOrThatQuestions[2].options[1] = "Watermelon";
    thisOrThatQuestions[2].type = THIS_OR_THAT;
    thisOrThatQuestions[2].hasCorrectAnswer = false;

    // This-or-That Question 4
    thisOrThatQuestions[3].question = "Which do you prefer?";
    thisOrThatQuestions[3].options[0] = "Ice cream";
    thisOrThatQuestions[3].options[1] = "Cake";
    thisOrThatQuestions[3].type = THIS_OR_THAT;
    thisOrThatQuestions[3].hasCorrectAnswer = false;

    // This-or-That Question 5
    thisOrThatQuestions[4].question = "Which do you prefer?";
    thisOrThatQuestions[4].options[0] = "Pizza";
    thisOrThatQuestions[4].options[1] = "Burger";
    thisOrThatQuestions[4].type = THIS_OR_THAT;
    thisOrThatQuestions[4].hasCorrectAnswer = false;

    // This-or-That Question 6
    thisOrThatQuestions[5].question = "Which do you prefer?";
    thisOrThatQuestions[5].options[0] = "Chocolate";
    thisOrThatQuestions[5].options[1] = "Vanilla";
    thisOrThatQuestions[5].type = THIS_OR_THAT;
    thisOrThatQuestions[5].hasCorrectAnswer = false;

    // This-or-That Question 7
    thisOrThatQuestions[6].question = "Which do you prefer?";
    thisOrThatQuestions[6].options[0] = "Cold drink";
    thisOrThatQuestions[6].options[1] = "Fresh juice";
    thisOrThatQuestions[6].type = THIS_OR_THAT;
    thisOrThatQuestions[6].hasCorrectAnswer = false;

    // This-or-That Question 8
    thisOrThatQuestions[7].question = "Which do you prefer?";
    thisOrThatQuestions[7].options[0] = "Popcorn";
    thisOrThatQuestions[7].options[1] = "Potato chips";
    thisOrThatQuestions[7].type = THIS_OR_THAT;
    thisOrThatQuestions[7].hasCorrectAnswer = false;

    // This-or-That Question 9
    thisOrThatQuestions[8].question = "Which do you prefer?";
    thisOrThatQuestions[8].options[0] = "Homemade food";
    thisOrThatQuestions[8].options[1] = "Restaurant food";
    thisOrThatQuestions[8].type = THIS_OR_THAT;
    thisOrThatQuestions[8].hasCorrectAnswer = false;

    // This-or-That Question 10
    thisOrThatQuestions[9].question = "Which do you prefer?";
    thisOrThatQuestions[9].options[0] = "Noodles";
    thisOrThatQuestions[9].options[1] = "Pasta";
    thisOrThatQuestions[9].type = THIS_OR_THAT;
    thisOrThatQuestions[9].hasCorrectAnswer = false;

    // This-or-That Question 11
    thisOrThatQuestions[10].question = "Which do you prefer?";
    thisOrThatQuestions[10].options[0] = "Donuts";
    thisOrThatQuestions[10].options[1] = "Cookies";
    thisOrThatQuestions[10].type = THIS_OR_THAT;
    thisOrThatQuestions[10].hasCorrectAnswer = false;

    // This-or-That Question 12
    thisOrThatQuestions[11].question = "Which do you prefer?";
    thisOrThatQuestions[11].options[0] = "Milkshake";
    thisOrThatQuestions[11].options[1] = "Smoothie";
    thisOrThatQuestions[11].type = THIS_OR_THAT;
    thisOrThatQuestions[11].hasCorrectAnswer = false;

    // This-or-That Question 13
    thisOrThatQuestions[12].question = "Which do you prefer?";
    thisOrThatQuestions[12].options[0] = "Apple";
    thisOrThatQuestions[12].options[1] = "Banana";
    thisOrThatQuestions[12].type = THIS_OR_THAT;
    thisOrThatQuestions[12].hasCorrectAnswer = false;

    // This-or-That Question 14
    thisOrThatQuestions[13].question = "Which do you prefer?";
    thisOrThatQuestions[13].options[0] = "French fries";
    thisOrThatQuestions[13].options[1] = "Onion rings";
    thisOrThatQuestions[13].type = THIS_OR_THAT;
    thisOrThatQuestions[13].hasCorrectAnswer = false;

    // This-or-That Question 15
    thisOrThatQuestions[14].question = "Which do you prefer?";
    thisOrThatQuestions[14].options[0] = "Hot coffee";
    thisOrThatQuestions[14].options[1] = "Cold coffee";
    thisOrThatQuestions[14].type = THIS_OR_THAT;
    thisOrThatQuestions[14].hasCorrectAnswer = false;

    // This-or-That Question 16
    thisOrThatQuestions[15].question = "Which do you prefer?";
    thisOrThatQuestions[15].options[0] = "Sandwich";
    thisOrThatQuestions[15].options[1] = "Wrap";
    thisOrThatQuestions[15].type = THIS_OR_THAT;
    thisOrThatQuestions[15].hasCorrectAnswer = false;

    // This-or-That Question 17
    thisOrThatQuestions[16].question = "Which do you prefer?";
    thisOrThatQuestions[16].options[0] = "Strawberry";
    thisOrThatQuestions[16].options[1] = "Butterscotch";
    thisOrThatQuestions[16].type = THIS_OR_THAT;
    thisOrThatQuestions[16].hasCorrectAnswer = false;

    // This-or-That Question 18
    thisOrThatQuestions[17].question = "Which do you prefer?";
    thisOrThatQuestions[17].options[0] = "Homemade sweets";
    thisOrThatQuestions[17].options[1] = "Bakery desserts";
    thisOrThatQuestions[17].type = THIS_OR_THAT;
    thisOrThatQuestions[17].hasCorrectAnswer = false;

    // This-or-That Question 19
    thisOrThatQuestions[18].question = "Which do you prefer?";
    thisOrThatQuestions[18].options[0] = "Fresh fruit juice";
    thisOrThatQuestions[18].options[1] = "Coconut water";
    thisOrThatQuestions[18].type = THIS_OR_THAT;
    thisOrThatQuestions[18].hasCorrectAnswer = false;

    // This-or-That Question 20
    thisOrThatQuestions[19].question = "Which do you prefer?";
    thisOrThatQuestions[19].options[0] = "Chocolate cake";
    thisOrThatQuestions[19].options[1] = "Vanilla ice cream";
    thisOrThatQuestions[19].type = THIS_OR_THAT;
    thisOrThatQuestions[19].hasCorrectAnswer = false;

    // This-or-That Question 21
    thisOrThatQuestions[20].question = "Which do you prefer?";
    thisOrThatQuestions[20].options[0] = "Lemonade";
    thisOrThatQuestions[20].options[1] = "Iced tea";
    thisOrThatQuestions[20].type = THIS_OR_THAT;
    thisOrThatQuestions[20].hasCorrectAnswer = false;

    // This-or-That Question 22
    thisOrThatQuestions[21].question = "Which do you prefer?";
    thisOrThatQuestions[21].options[0] = "White chocolate";
    thisOrThatQuestions[21].options[1] = "Dark chocolate";
    thisOrThatQuestions[21].type = THIS_OR_THAT;
    thisOrThatQuestions[21].hasCorrectAnswer = false;

    // This-or-That Question 23
    thisOrThatQuestions[22].question = "Which do you prefer?";
    thisOrThatQuestions[22].options[0] = "Pancakes";
    thisOrThatQuestions[22].options[1] = "Waffles";
    thisOrThatQuestions[22].type = THIS_OR_THAT;
    thisOrThatQuestions[22].hasCorrectAnswer = false;

    // This-or-That Question 24
    thisOrThatQuestions[23].question = "Which do you prefer?";
    thisOrThatQuestions[23].options[0] = "Morning";
    thisOrThatQuestions[23].options[1] = "Night";
    thisOrThatQuestions[23].type = THIS_OR_THAT;
    thisOrThatQuestions[23].hasCorrectAnswer = false;

    // This-or-That Question 25
    thisOrThatQuestions[24].question = "Which do you prefer?";
    thisOrThatQuestions[24].options[0] = "Peaceful and quiet";
    thisOrThatQuestions[24].options[1] = "Lively and energetic";
    thisOrThatQuestions[24].type = THIS_OR_THAT;
    thisOrThatQuestions[24].hasCorrectAnswer = false;

    // This-or-That Question 26
    thisOrThatQuestions[25].question = "Which do you prefer?";
    thisOrThatQuestions[25].options[0] = "At home";
    thisOrThatQuestions[25].options[1] = "At a cinema";
    thisOrThatQuestions[25].type = THIS_OR_THAT;
    thisOrThatQuestions[25].hasCorrectAnswer = false;

    // This-or-That Question 27
    thisOrThatQuestions[26].question = "Which do you prefer?";
    thisOrThatQuestions[26].options[0] = "Write about it";
    thisOrThatQuestions[26].options[1] = "Take a photograph";
    thisOrThatQuestions[26].type = THIS_OR_THAT;
    thisOrThatQuestions[26].hasCorrectAnswer = false;

    // This-or-That Question 28
    thisOrThatQuestions[27].question = "Which do you prefer?";
    thisOrThatQuestions[27].options[0] = "Reading a book";
    thisOrThatQuestions[27].options[1] = "Listening to music";
    thisOrThatQuestions[27].type = THIS_OR_THAT;
    thisOrThatQuestions[27].hasCorrectAnswer = false;

    // This-or-That Question 29
    thisOrThatQuestions[28].question = "Which do you prefer?";
    thisOrThatQuestions[28].options[0] = "Board games";
    thisOrThatQuestions[28].options[1] = "Video games";
    thisOrThatQuestions[28].type = THIS_OR_THAT;
    thisOrThatQuestions[28].hasCorrectAnswer = false;

    // This-or-That Question 30
    thisOrThatQuestions[29].question = "Which do you prefer?";
    thisOrThatQuestions[29].options[0] = "Dancing";
    thisOrThatQuestions[29].options[1] = "Singing";
    thisOrThatQuestions[29].type = THIS_OR_THAT;
    thisOrThatQuestions[29].hasCorrectAnswer = false;
    
    // Written-answer Question 1
    writtenQuestions[0].question = "What time do you usually wake up?";
    writtenQuestions[0].type = WRITTEN_ANSWER;
    writtenQuestions[0].hasCorrectAnswer = false;

    // Written-answer Question 2
    writtenQuestions[1].question = "Are you an introvert or an extrovert?";
    writtenQuestions[1].type = WRITTEN_ANSWER;
    writtenQuestions[1].hasCorrectAnswer = false;

    // Written-answer Question 3
    writtenQuestions[2].question = "Which month is your birthday in?";
    writtenQuestions[2].type = WRITTEN_ANSWER;
    writtenQuestions[2].hasCorrectAnswer = false;

    // Written-answer Question 4
    writtenQuestions[3].question = "Which matters more to you: success or happiness?";
    writtenQuestions[3].type = WRITTEN_ANSWER;
    writtenQuestions[3].hasCorrectAnswer = false;

    // Written-answer Question 5
    writtenQuestions[4].question = "What quality do you value most in a friend?";
    writtenQuestions[4].type = WRITTEN_ANSWER;
    writtenQuestions[4].hasCorrectAnswer = false;

    // Written-answer Question 6
    writtenQuestions[5].question = "What motivates you most to achieve a goal?";
    writtenQuestions[5].type = WRITTEN_ANSWER;
    writtenQuestions[5].hasCorrectAnswer = false;

    // Written-answer Question 7
    writtenQuestions[6].question = "What is one word that describes your biggest dream?";
    writtenQuestions[6].type = WRITTEN_ANSWER;
    writtenQuestions[6].hasCorrectAnswer = false;

    // Written-answer Question 8
    writtenQuestions[7].question = "What type of movie do you enjoy most?";
    writtenQuestions[7].type = WRITTEN_ANSWER;
    writtenQuestions[7].hasCorrectAnswer = false;

    // Written-answer Question 9
    writtenQuestions[8].question = "Which musical instrument would you like to learn?";
    writtenQuestions[8].type = WRITTEN_ANSWER;
    writtenQuestions[8].hasCorrectAnswer = false;

    // Written-answer Question 10
    writtenQuestions[9].question = "What is one word that describes your closest friend?";
    writtenQuestions[9].type = WRITTEN_ANSWER;
    writtenQuestions[9].hasCorrectAnswer = false;

    // Written-answer Question 11
    writtenQuestions[10].question = "Which mode of transport do you use most often?";
    writtenQuestions[10].type = WRITTEN_ANSWER;
    writtenQuestions[10].hasCorrectAnswer = false;

    // Written-answer Question 12
    writtenQuestions[11].question = "If you could create something, what would it be?";
    writtenQuestions[11].type = WRITTEN_ANSWER;
    writtenQuestions[11].hasCorrectAnswer = false;

    // Written-answer Question 13
    writtenQuestions[12].question = "What do you usually do when you feel bored?";
    writtenQuestions[12].type = WRITTEN_ANSWER;
    writtenQuestions[12].hasCorrectAnswer = false;

    // Written-answer Question 14
    writtenQuestions[13].question = "What is your favourite way to celebrate a special day?";
    writtenQuestions[13].type = WRITTEN_ANSWER;
    writtenQuestions[13].hasCorrectAnswer = false;

    // Written-answer Question 15
    writtenQuestions[14].question = "What is one word you would use to describe yourself?";
    writtenQuestions[14].type = WRITTEN_ANSWER;
    writtenQuestions[14].hasCorrectAnswer = false;

    // Written-answer Question 16
    writtenQuestions[15].question = "What is your favourite thing to collect?";
    writtenQuestions[15].type = WRITTEN_ANSWER;
    writtenQuestions[15].hasCorrectAnswer = false;

    // Written-answer Question 17
    writtenQuestions[16].question = "Which language would you like to learn?";
    writtenQuestions[16].type = WRITTEN_ANSWER;
    writtenQuestions[16].hasCorrectAnswer = false;

    // Written-answer Question 18
    writtenQuestions[17].question = "What do you usually drink in the morning?";
    writtenQuestions[17].type = WRITTEN_ANSWER;
    writtenQuestions[17].hasCorrectAnswer = false;

    // Written-answer Question 19
    writtenQuestions[18].question = "Which festival do you enjoy most?";
    writtenQuestions[18].type = WRITTEN_ANSWER;
    writtenQuestions[18].hasCorrectAnswer = false;

    // Written-answer Question 20
    writtenQuestions[19].question = "What is your favourite indoor activity?";
    writtenQuestions[19].type = WRITTEN_ANSWER;
    writtenQuestions[19].hasCorrectAnswer = false;

    // Written-answer Question 21
    writtenQuestions[20].question = "Which game do you enjoy playing most?";
    writtenQuestions[20].type = WRITTEN_ANSWER;
    writtenQuestions[20].hasCorrectAnswer = false;

    // Written-answer Question 22
    writtenQuestions[21].question = "What is your favourite flower?";
    writtenQuestions[21].type = WRITTEN_ANSWER;
    writtenQuestions[21].hasCorrectAnswer = false;

    // Written-answer Question 23
    writtenQuestions[22].question = "Which subject do you enjoy studying most?";
    writtenQuestions[22].type = WRITTEN_ANSWER;
    writtenQuestions[22].hasCorrectAnswer = false;

    // Written-answer Question 24
    writtenQuestions[23].question = "Which part of the day do you like the most?";
    writtenQuestions[23].type = WRITTEN_ANSWER;
    writtenQuestions[23].hasCorrectAnswer = false;

    // Written-answer Question 25
    writtenQuestions[24].question = "What is one thing that makes you smile?";
    writtenQuestions[24].type = WRITTEN_ANSWER;
    writtenQuestions[24].hasCorrectAnswer = false;

    // Written-answer Question 26
    writtenQuestions[25].question = "Which programming language do you like the most?";
    writtenQuestions[25].type = WRITTEN_ANSWER;
    writtenQuestions[25].hasCorrectAnswer = false;

    // Written-answer Question 27
    writtenQuestions[26].question = "Which area of computer science interests you the most?";
    writtenQuestions[26].type = WRITTEN_ANSWER;
    writtenQuestions[26].hasCorrectAnswer = false;

    // Written-answer Question 28
    writtenQuestions[27].question = "What kind of programming problems do you enjoy solving?";
    writtenQuestions[27].type = WRITTEN_ANSWER;
    writtenQuestions[27].hasCorrectAnswer = false;

    // Written-answer Question 29
    writtenQuestions[28].question = "What would you most like to build with code?";
    writtenQuestions[28].type = WRITTEN_ANSWER;
    writtenQuestions[28].hasCorrectAnswer = false;

    // Written-answer Question 30
    writtenQuestions[29].question = "Which computer science topic interests you most?";
    writtenQuestions[29].type = WRITTEN_ANSWER;
    writtenQuestions[29].hasCorrectAnswer = false;
}

// Returns a random question from initialised category
PersonalQuestion getRandomPersonalQuestion(int category)
{
    int index = rand() % 30;

    if (category == MCQ)
        return mcqQuestions[index];

    else if (category == THIS_OR_THAT)
        return thisOrThatQuestions[index];

    else
        return writtenQuestions[index];
}

// To display a personal question and returns the player's answer
string askPersonalQuestion(PersonalQuestion question)
{
    cout<<"\n\n==================   DIGIT CHALLENGE   ================\n";
    cout << "\n" << question.question << "\n";

    // Written-answer question
    if (question.type == WRITTEN_ANSWER)
    {
        string answer;

        cout << "Your answer: ";
        getline(cin >> ws, answer);

        return answer;
    }

    int optionCount;

    if (question.type == MCQ)
        optionCount = 4;
    else
        optionCount = 2;

    for (int i = 0; i < optionCount; i++)
    {
        cout << i + 1 << ". "
             << question.options[i] << "\n";
    }

    int choice;

    while (true)
    {
        cout << "Enter your choice (1-" << optionCount << "): ";

        if (cin >> choice && choice >= 1 && choice <= optionCount)
            break;

        cout << "Invalid input. Please enter a number from 1 to "
             << optionCount << ".\n";

        cin.clear();
        cin.ignore(10000, '\n');
    }

    return question.options[choice - 1];
}

// Checks whether answer is valid according to question category
bool isPersonalAnswerValid(PersonalQuestion question, string answer)
{
    // Check whether the answer contains at least one non-space character.
    bool hasText = false;

    for (int i = 0; i < answer.length(); i++)
    {
        if (!isspace(static_cast<unsigned char>(answer[i])))
        {
            hasText = true;
            break;
        }
    }

    if (!hasText)
        return false;

    // Preference-based written questions must contain at least one letter.
    if (question.type == WRITTEN_ANSWER && question.hasCorrectAnswer == false)
    {
        bool hasLetter = false;

        for (int i = 0; i < answer.length(); i++)
        {
            char ch = answer[i];

            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            {
                hasLetter = true;
                break;
            }
        }

        return hasLetter;
    }

    // Preference-based MCQs and This-or-That questions accept either choice.
    if (question.hasCorrectAnswer == false)
        return true;

    // Check the selected option for questions with a correct answer.
    for (int i = 0; i < 4; i++)
    {
        if (answer == question.options[i])
        {
            return (i + 1 == question.correctOption);
        }
    }

    return false;
}

// Randomly selects two different categories
void choosePersonalQuestionCategories(int &firstCategory, int &secondCategory)
{
    firstCategory = rand() % 3 + 1;

    do
    {
        secondCategory = rand() % 3 + 1;
    }
    while (secondCategory == firstCategory);
}

// Convert the letter and numerical values to single digit 
int convertAnswerToSingleDigit(string answer)
{
    int total = 0;
     
    // Process each character in the answer
    for (int i = 0; i < answer.length(); i++)
    {
        char ch = answer[i];

        // Convert lowercase letters to uppercase
        if (ch >= 'a' && ch <= 'z')
            ch = ch - 'a' + 'A';

        // Letters A-Z contribute values 1-26
        if (ch >= 'A' && ch <= 'Z')
            total += ch - 'A' + 1;

        // Digits contribute their numeric values, spaces and special characters ignored
        else if (ch >= '0' && ch <= '9')
            total += ch - '0';
    }

    // Repeatedly add the digts until a single digit remains
    while (total >= 10)
    {
        int digitSum = 0;

        while (total > 0)
        {
            digitSum += total % 10;
            total /= 10;
        }

        total = digitSum;
    }

    return total;
}

// Combines single digit of two answers to produce the code digit
int calculateDigit2(string firstAnswer, string secondAnswer)
{
    int firstDigit = convertAnswerToSingleDigit(firstAnswer);
    int secondDigit = convertAnswerToSingleDigit(secondAnswer);

    int total = firstDigit + secondDigit;

    // Reduce the combined result to one digit
    while (total >= 10)
    {
        int digitSum = 0;

        while (total > 0)
        {
            digitSum += total % 10;
            total /= 10;
        }

        total = digitSum;
    }

    return total;
}

// Runs two personal questions , validate the answer and calculates the hidden digit
bool playPersonalQuestionTest()
{
    int firstCategory;
    int secondCategory;

    choosePersonalQuestionCategories(firstCategory, secondCategory);

    PersonalQuestion firstQuestion = getRandomPersonalQuestion(firstCategory);

    PersonalQuestion secondQuestion = getRandomPersonalQuestion(secondCategory);

    int firstInvalidAttempts = 0;
    int secondInvalidAttempts = 0;

    string firstAnswer;
    string secondAnswer;

    // Ask the first question
    while (firstInvalidAttempts < 2)
    {
        firstAnswer = askPersonalQuestion(firstQuestion);

        if (isPersonalAnswerValid(firstQuestion, firstAnswer))
            break;

        firstInvalidAttempts++;

        if (firstInvalidAttempts < 2)
        {
            cout << "\nIncorrect answer. Here's a new question.\n";

            PersonalQuestion previousQuestion = firstQuestion;

            do
            {
                firstQuestion = getRandomPersonalQuestion(firstCategory);
            }
            while (firstQuestion.question == previousQuestion.question);
        }
    }

    if (firstInvalidAttempts >= 2)
    {
        offerModeSwitch();
        return false;
    }

    // Ask the second question using its own invalid-answer counter
    while (secondInvalidAttempts < 2)
    {
        secondAnswer = askPersonalQuestion(secondQuestion);

        if (isPersonalAnswerValid(secondQuestion, secondAnswer))
            break;

        secondInvalidAttempts++;

        if (secondInvalidAttempts < 2)
        {
            cout << "\nIncorrect answer. Here's a new question.\n";

            PersonalQuestion previousQuestion = secondQuestion;

            do
            {
                secondQuestion = getRandomPersonalQuestion(secondCategory);
            }
            while (secondQuestion.question == previousQuestion.question);
        }
    }

    if (secondInvalidAttempts >= 2)
    {
        offerModeSwitch();
        return false;
    }

    savedDigit2 = calculateDigit2(firstAnswer, secondAnswer);
    
    cout << "\nBoth answers have been accepted!\n";
    
    return true;
}

// FUNCTIONS FOR DIGIT CHALLENGE
void playDigit2Challenge()
{
    int attempts = 0;
    bool correct = false;

    while (attempts < 2 && !correct)
    {
        if (!playPersonalQuestionTest())
            return;

        long long guess;

        cout << "\nFind the hidden digit to unlock the fourth character.";
        cout << "\nEnter a digit (0-9): ";
        guess = getValidNumber();

        if (guess == savedDigit2)
        {
            digit2Solved = true;
            correct = true;

            cout << "\nCorrect! You unlocked the fourth character!\n";

            showDigit2Progress(savedSpecialCharacter, savedDigit, savedAlphaCharacter, savedDigit2);
        }
        else
        {
            attempts++;

            if (attempts < 2)
                cout << "\nIncorrect! You have one more attempt.\n";
            else
            {
                 offerModeSwitch();
            }
        }
    }
}

// Stores three names , their corresponding letters and puzzle generation details
struct AlphabetPuzzle
{
    string names[3];
    char alphabets[3];

    int patternNumber;
    int hiddenPosition;

    string puzzleSignature;
};

// This is the size of name bank and maximum number of unique puzzles 
const int TOTAL_NAMES = 240;
const int MAX_PUZZLES = 80;

// 240 names used for final alphabet challenge
string nameBank[TOTAL_NAMES] =
{
    // Indian Male Names
    "Aarav", "Advait", "Arjun", "Aditya", "Akash", "Aman", "Aniket", "Anirudh", "Aryan", "Atharv","Ayush", "Bharat",
    "Chirag", "Dev", "Dhruv", "Gaurav", "Harsh", "Ishaan", "Madhav", "Karan", "Kartik", "Kunal", "Lakshya", "Manav", 
    "Mohit", "Nakul", "Nikhil", "Raghav", "Pranav", "Rahul", "Parth", "Rohan", "Rudra", "Sahil", "Sameer", "Shaurya",
    "Siddharth", "Tanmay", "Uday", "Varun", "Vedant", "Vihaan", "Yash", "Zoravar", "Kabir", "Abeer", "Abhimanyu", "Akhil", 
    "Amol", "Arnav", "Darsh", "Divyansh", "Eklavya", "Hriday", "Jay", "Keshav", "Omkar", "Reyansh", "Samar", "Shreyas",
    
    // Indian Female Names
    "Aadhya", "Aanya", "Aditi", "Akanksha", "Ananya", "Anika", "Anjali", "Anushka", "Avni", "Bhavya", "Diya", "Esha",
    "Gauri", "Isha", "Jhanvi", "Kavya", "Khushi", "Kiara", "Kriti", "Lavanya", "Meera", "Myra", "Naina", "Navya", 
    "Neha", "Nisha", "Pari", "Pihu", "Prisha", "Radhika", "Riya", "Saanvi", "Sanjana", "Sara", "Shanaya", "Anvi", 
    "Siya", "Sneha", "Tanvi", "Tara", "Trisha", "Vaishnavi", "Vanya", "Yashvi", "Zoya", "Aishwarya", "Amrita", "Anushree", 
    "Charvi", "Disha", "Ishita", "Ira", "Kashvi", "Mahi", "Mannat","Mrunal", "Ritika", "Sakshi", "Priya", "Urvi",

    // International Male Names
    "Alexander", "Benjamin", "Caleb", "Daniel", "Ethan", "Felix", "Gabriel", "Henry", "Isaac", "Jacob", "James", "Julian",
    "Leo", "Liam", "Lucas", "Mason", "Matthew", "Michael", "Nathan", "Noah", "Oliver", "Oscar", "Owen", "Patrick", "Peter",
    "Ryan", "Samuel", "Sebastian", "Thomas", "Victor", "William", "Xavier", "Adrian", "Andrew", "Anthony", "Arthur", 
    "Blake", "Brandon", "Christopher", "David", "Edward", "George", "Hugo", "Jack", "Kevin","Aaron", "Aiden", "Alan",
    "Albert", "Alfred","Austin", "Carl", "Charles", "Dominic", "Dylan","Eric", "Evan", "Finn", "Jason", "Jonathan",

    // International Female Names
    "Abigail", "Alice", "Amelia", "Anna", "Audrey", "Bella", "Caroline", "Charlotte", "Chloe", "Claire", "Daisy", "Eleanor",
    "Elena", "Elizabeth", "Emily", "Emma", "Eva", "Fiona", "Grace", "Hannah", "Hazel", "Isabella", "Jasmine", "Jessica", 
    "Julia", "Lily", "Lucy", "Madison", "Maya", "Mia", "Natalie", "Olivia", "Penelope", "Rachel", "Rebecca", "Rose", 
    "Ruby", "Sophia", "Stella", "Violet", "Wendy", "Zoe", "Nora", "Sarah", "Victoria","Aria", "Ashley", "Autumn", 
    "Brooklyn", "Cora", "Delilah", "Ella", "Esther", "Evelyn", "Gabriella", "Georgia", "Harper", "Iris", "Leah", "Naomi",
};

// To track name and puzzle pattern that have been already used
bool usedNames[TOTAL_NAMES] = {};
string usedSignatures[MAX_PUZZLES];
int usedPuzzleCount = 0;

// Calculate the sum of alphabet position of all letters in a name
int calculateAlphabetSum(string name)
{
    int sum = 0;

    for (int i = 0; i < name.length(); i++)
    {
        char letter = name[i];

        // Convert lowercase letters into uppercase
        if (letter >= 'a' && letter <= 'z')
        {
            letter = letter - 'a' + 'A';
        }

        // Calculate alphabet position
        if (letter >= 'A' && letter <= 'Z')
        {
            sum += letter - 'A' + 1;
        }
    }

    return sum;
}

// Reduces a name's alphabet position sum to single digit
int calculateNameDigit(string name)
{
    int sum = calculateAlphabetSum(name);

    int singleDigit = reduceToSingleDigit(sum);

    return singleDigit;
}

// Applies the mathematical pattern to a single digit value
long long applyAlphabetPattern(int number, int patternNumber)
{
    switch (patternNumber)
    {
        case 1:
            return number;                         // S

        case 2:
            return number * number - number;       // S^2 - S

        case 3:
            return number * number + number;       // S^2 + S

        case 4:
            return number * number * number - number; // S^3 - S

        case 5:
            return number * number * number + number; // S^3 + S

        default:
            return -1;
    }
}

// Calculate the corresponding alphabet character for each of three names
void calculatePuzzleAlphabets(AlphabetPuzzle &puzzle, int patternNumber)
{
    puzzle.patternNumber = patternNumber;

    for (int i = 0; i < 3; i++)
    {
        int S = calculateNameDigit(puzzle.names[i]);

        long long result = applyAlphabetPattern(S, patternNumber);

        puzzle.alphabets[i] = getAlphabetCharacter(result);
    }
}

// Randomly selects one of numerical pattern out of five patterns
int generateRandomAlphabetPattern()
{
    return rand() % 5 + 1;
}

// Randomly selects which of letter will be hidden
int generateHiddenAlphabetPosition()
{
    return rand() % 3;
}

// Randomly selects three names that have not been used
bool selectThreeNames(AlphabetPuzzle &puzzle, string nameBank[], bool usedNames[])
{
    int availableNames = 0;

    // Count names that have not been used yet.
    for (int i = 0; i < TOTAL_NAMES; i++)
    {
        if (!usedNames[i])
            availableNames++;
    }

    // We need at least three available names.
    if (availableNames < 3)
        return false;

    int selectedIndices[3];

    for (int i = 0; i < 3; i++)
    {
        int randomIndex;

        do
        {
            randomIndex = rand() % TOTAL_NAMES;

        } while (usedNames[randomIndex] || (i >= 1 && randomIndex == selectedIndices[0]) ||
                (i >= 2 && randomIndex == selectedIndices[1]));

        selectedIndices[i] = randomIndex;
        puzzle.names[i] = nameBank[randomIndex];
    }

    return true;
}

// To make sure that the two visible name-letter pairs identify exactly one pattern
bool hasUniquePattern(AlphabetPuzzle &puzzle)
{
    int matchingPatterns = 0;

    // Check all five possible patterns
    for (int pattern = 1; pattern <= 5; pattern++)
    {
        bool matches = true;

        // Check only the two visible names
        for (int i = 0; i < 3; i++)
        {
            if (i == puzzle.hiddenPosition)
                continue;

            int S = calculateNameDigit(puzzle.names[i]);

            long long result = applyAlphabetPattern(S, pattern);

            char calculatedAlphabet = getAlphabetCharacter(result);

            if (calculatedAlphabet != puzzle.alphabets[i])
            {
                matches = false;
                break;
            }
        }

        if (matches)
            matchingPatterns++;
    }

    return matchingPatterns == 1;
}

// Generates a valid puzzle by using three unused names and one randomly selected pattern
bool generateAlphabetPuzzle(AlphabetPuzzle &puzzle, string nameBank[], bool usedNames[])
{
    // Select three different, unused names.
    if (!selectThreeNames(puzzle, nameBank, usedNames))
        return false;

    // Select one pattern for all three names
    int patternNumber = generateRandomAlphabetPattern();

    // Randomly decide which alphabet will be hidden
    puzzle.hiddenPosition = generateHiddenAlphabetPosition();

    // Calculate all three alphabets using the same pattern
    calculatePuzzleAlphabets(puzzle, patternNumber);

    // Accept only puzzles with exactly one possible pattern
    if (!hasUniquePattern(puzzle))
        return false;

    return true;
}

// Creates a unique identifier using the name, pattern and hidden position
string createPuzzleSignature(AlphabetPuzzle &puzzle)
{
    string signature = "";

    for (int i = 0; i < 3; i++)
    {
        signature += puzzle.names[i] + "|";
    }

    signature += to_string(puzzle.patternNumber) + "|";
    signature += to_string(puzzle.hiddenPosition);

    return signature;
}

// Checks whether the puzzle signature is present in history 
bool isPuzzleAlreadyUsed(string signature, string usedSignatures[], int usedPuzzleCount)
{
    for (int i = 0; i < usedPuzzleCount; i++)
    {
        if (signature == usedSignatures[i])
            return true;
    }

    return false;
}

// The maximum attempt defined to generate an unused and valid puzzle
const int MAX_GENERATION_ATTEMPTS = 1000;

// Generates puzzle candidates repeatedly until it finds a new, unused puzzle or reaches the generation limit
bool generateUniqueAlphabetPuzzle(AlphabetPuzzle &puzzle)
{
    int generationAttempts = 0;

    while (usedPuzzleCount < MAX_PUZZLES && generationAttempts < MAX_GENERATION_ATTEMPTS)
    {
        generationAttempts++;

        // Generate a new puzzle candidate
        if (!generateAlphabetPuzzle(puzzle, nameBank, usedNames))
            continue;

        // Create its signature
        puzzle.puzzleSignature = createPuzzleSignature(puzzle);

        // Check whether this puzzle has appeared before
        if (!isPuzzleAlreadyUsed(puzzle.puzzleSignature, usedSignatures, usedPuzzleCount))
        {
            return true;
        }
    }

    return false;
}

void markPuzzleAsUsed(AlphabetPuzzle &puzzle, string nameBank[], bool usedNames[], string usedSignatures[], int &usedPuzzleCount)
{
    // Mark the three selected names as used.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < TOTAL_NAMES; j++)
        {
            if (puzzle.names[i] == nameBank[j])
            {
                usedNames[j] = true;
                break;
            }
        }
    }

    // Store the accepted puzzle's signature
    usedSignatures[usedPuzzleCount] = puzzle.puzzleSignature;

    usedPuzzleCount++;
}

// Displays the three names and hides one letter so that player can identify it 
void displayAlphabetPuzzle(AlphabetPuzzle &puzzle)
{
    cout << "\n========== FINAL ALPHABET CHALLENGE ==========\n\n";

    for (int i = 0; i < 3; i++)
    {
        cout<< puzzle.names[i] << "  ----->  ";

        if (i == puzzle.hiddenPosition)
        {
            cout << "?";
        }
        else
        {
            cout << puzzle.alphabets[i];
        }

        cout << endl;
    }

    cout << "\nFind the missing alphabet!\n";
}

// Accepts and validates the alphabet given by player
char getPlayerAlphabetAnswer()
{
    string answer;

    cout << "\nEnter the missing alphabet: ";
    cin >> answer;

    // Accept only English alphabet characters
    while (answer.length() !=1 || !((answer[0] >= 'A' && answer[0] <= 'Z') || (answer[0] >= 'a' && answer[0] <= 'z')))
    {
        cout << "Invalid input! Enter an alphabet: ";
        cin >> answer;
    }

    return answer[0];
}

// Checks the player's answer against the hidden alphabet character
bool checkAlphabetAnswer(AlphabetPuzzle &puzzle, char playerAnswer)
{
    // Convert lowercase input into uppercase.
    if (playerAnswer >= 'a' && playerAnswer <= 'z')
    {
        playerAnswer = playerAnswer - 'a' + 'A';
    }

    return playerAnswer == puzzle.alphabets[puzzle.hiddenPosition];
}

// FUNCTIONS FOR ALPHABET CHALLENGE
void playFinalAlphabetChallenge()
{
    AlphabetPuzzle puzzle;

    // Generate a new puzzle that hasn't appeared before
    if (!generateUniqueAlphabetPuzzle(puzzle))
    {
        cout << "\nThe Puzzle Master has run out of challenges!\n";
        cout << "Please try another mode.\n";
        offerModeSwitch();
        return;
    }

    // Mark the generated puzzle and its names as used
    markPuzzleAsUsed(puzzle, nameBank, usedNames, usedSignatures, usedPuzzleCount);

    // Give the player two attempts.
    for (int attempt = 1; attempt <= 2; attempt++)
    {
        displayAlphabetPuzzle(puzzle);

        cout << "\nAttempt " << attempt << " of 2\n";

        char playerAnswer = getPlayerAlphabetAnswer();

        if (checkAlphabetAnswer(puzzle, playerAnswer))
        {
            cout << "\nCorrect! You solved the Final Alphabet Challenge!\n";

            alpha2Solved = true;

            cout << "\n****************************************\n";
            cout << "       CONGRATULATIONS!\n";
            cout << "      YOU SOLVED THE CODE!\n";
            cout << "*****************************************\n";

            cout << "\nThe Locked Room Code: "<<savedSpecialCharacter<<" "<<savedDigit<<" "<<savedAlphaCharacter<<" "
            <<savedDigit2<<" "<<puzzle.alphabets[puzzle.hiddenPosition];

            cout << "\n\nYou have successfully unlocked the room!\n";

            return;
        }
        else
        {
            cout << "\nIncorrect alphabet!\n";

            if (attempt == 1)
            {
                cout << "You have one more attempt.\n";
            }
            else
            {
                cout << "Both attempts are over.\n";
                offerModeSwitch();
                return;
            }
        }
    }
}

void playPuzzleMode()
{
    int attempts = 0;
    bool passed = false;

    if (!specialSolved)
    {
        while(attempts < 2 && passed == false)
        {
            SpecialPattern pattern = generatePattern();
            char correctCharacter = getKeyboardCharacter(pattern.missingDigit);

            displayPattern(pattern);

            char guess = getPlayerGuess();
    
            passed = checkPatternAnswer(pattern, guess);

            if (passed == true)
            {
                specialSolved = true;
                savedSpecialCharacter = correctCharacter;

                cout << "\nCode Progress: "
                    << correctCharacter << " _ _ _ _" << endl;
    
            }

            attempts++;

        }
    
        if (passed == false)
        {
            offerModeSwitch();
        }
    }

    // DIGIT CHALLENGE

    if (specialSolved && !digitSolved)
    {
        playDigitPuzzle();
    }

    // ALPHA CHALLENGE

    if (specialSolved && digitSolved && !alphaNumberSolved)
    {
        playAlphaPuzzle();
    }
    
    // DIGIT CHALLENGE 

    if (specialSolved && digitSolved && alphaNumberSolved && !digit2Solved)
    {
        playDigit2Challenge();
    }

    // FINAL ALPHABET CHALLENGE

    if (specialSolved && digitSolved && alphaNumberSolved && digit2Solved && !alpha2Solved)
    {
        playFinalAlphabetChallenge();
    }
}

void resetGameProgress()
{
    specialSolved = false;
    savedSpecialCharacter = ' ';

    digitSolved = false;
    savedDigit = -1;

    alphaNumberSolved = false;
    savedAlphaCharacter = ' ';

    digit2Solved = false;
    savedDigit2 = -1;

    alpha2Solved = false;
    savedAlpha2 = ' ';

    // Reset the final alphabet puzzle data.
    for (int i = 0; i < TOTAL_NAMES; i++)
    {
        usedNames[i] = false;
    }

    for (int i = 0; i < MAX_PUZZLES; i++)
    {
        usedSignatures[i] = "";
    }
    
    usedMathsQuestionCount = 0;
    usedPuzzleCount = 0;
}

int main() 
{ 
    srand(time(0));
    initializePersonalQuestions();
    
    string name; 
 
    cout<<"Hello! What's your name : "; 
    getline(cin, name); 
     
    intro(); 
 
    poster(); 
    
    welcome(); 
 
    box(); 
 
    while(true)
    {
        cout<<"\n+----------------------------------------------------------------+"<<endl; 
        cout<<"|                         MAKE YOUR CHOICE                        |"<<endl; 
        cout<<"+----------------------------------------------------------------+"<<endl; 
        cout<<"\n 1. Solve By Maths Mode" 
            <<"\n 2. Solve By Puzzle Mode"<<endl; 
         
        cout << "Enter your choice: ";
        int choice = getValidChoice(2); 
         
        switch(choice) 
        { 
            case 1: 
            { 
                playMathsMode();

                break;
            }

            case 2 :
            {
                playPuzzleMode();
                break;
            }

            default:
            cout << "\nInvalid Choice" << endl;
            continue;
        }

        cout << "\n+----------------------------------------------------------------+" << endl;
        cout << "|                         PLAY AGAIN?                             |" << endl;
        cout << "+----------------------------------------------------------------+" << endl;

        cout << "\n 1. Play Again"
            << "\n 2. Exit Game" << endl;

        cout << "Enter your choice: ";
        int replayChoice = getValidChoice(2);

        if (replayChoice == 1)
        {
            resetGameProgress();
            cout << "\nStarting a new game...\n";
        }
        else if (replayChoice == 2)
        {
            cout << "\nThanks for playing The Locked Room!\n";
            break;
        }
        else
        {
            cout << "\nInvalid Choice! Exiting Game.\n";
            break;
        }
    }

    return 0;
}