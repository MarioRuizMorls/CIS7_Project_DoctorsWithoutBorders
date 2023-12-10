
#include <iostream>
#include <map>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;
struct Country {//struct Country, to hold the information of each country
    string name;//string to store the name of the country
    vector<string> languages;//string vector to hold the languages spoken in the country
    vector<string> specialties;//string vector to hold the specialties needed in the country
};

bool isValid(string& , int, int);//isValid prototype
void printCountries(vector<Country>);//printCountries prototype
void probability(vector<Country> countries, string language, string speciality, string country);//probability prototype

int main(int argc, const char * argv[]) {
    //string variables to hold user input
    string language;//user language input
    string specialty;//user specialty input
    string country;//user country input
   
    //maps that store the languages, specialties, and countries
    map<string, string> languageMap =
    {   {"1","French"},{"2","Spanish"}, {"3","Português"},
        {"4","Arabic"}, {"5","Tagolog"}

    };
    map<string, string> specialityMap =
    {   {"1","Cardiology"},{"2","Hematology"}, {"3","Neurology"},
        {"4","Allergy and Immunology"}, {"5","Orthopedics"}, {"6","Pediatrics"}

    };
    map<string, string> countryMap =
    {   {"1","Mexico"},{"2","Brazil"}, {"3","Cameroon"},
        {"4","Ivory Coast"}, {"5","Egypt"},{"6","Morocco"},
        {"7","Philippines"},{"8","France"}, {"9","United States"},
        {"10","French Guiana"}

    };
    
    //vector of Country struct objects, initialized with all the coutries that are participating in the program
    vector<Country>countries = {
        {"Mexico", {"Spanish"}, {"Cardiology", "Orthopedics"}},
        {"Brazil", {"Português"}, {"Hematology", "Pediatrics"}},
        {"Cameroon", {"French", "English"}, {"Neurology", "Cardiology", "Orthopedics"}},
        {"Ivory Coast", {"French"}, {"Allergy and Immunology"}},
        {"Egypt", {"Arabic"}, {"Orthopedics"}},
        {"Morocco", {"Arabic", "French"}, {"Pediatrics", "Orthopedics", "Allergy and Immunology"}},
        {"Philippines", {"Tagalog"}, {"Cardiology", "Pediatrics"}},
        {"France", {"French"}, {"Cardiology", "Hematology"}},
        {"Mozambique", {"Português"}, {"Cardiology", "Orthopedics"}},
        {"French Guiana", {"Spanish", "French"}, {"Hematology", "Pediatrics"}}
    };
    
    //print and display all the coutries along with their information allowing the user to have an idea
    //of which coutries they can choose from and what requirements do they need for each country
    printCountries(countries);

    //ask the user the language they know
    cout << "Hello Student please select which language your are best at besides english?" <<endl;
    cout << "1. French" <<endl;
    cout << "2. Spanish" <<endl;
    cout << "3. Portuguese" <<endl;
    cout << "4. Arabic" <<endl;
    cout << "5. Tagolog" <<endl;

    cout << "Please choose a number 1-5: ";
    cin >> language;//stores user input
    while(!isValid(language, 1,5)){//validates the users answer to be only from the selected choices
        cout << "Please only choose a vaild answer";
        cin >> language;
    }


    cout << "\n";

    //ask the user the speciality they know
    cout << "Hello Student please select which speciality you are studying?" <<endl;
    cout << "1. Cardiology" <<endl;
    cout << "2. Hematology" <<endl;
    cout << "3. Neurology" <<endl;
    cout << "4. Allery and Immunology" <<endl;
    cout << "5. Orthopedics" <<endl;
    cout << "6. Pediatrics" <<endl;

    cout << "Please choose a number 1-6: ";
    cin >> specialty;//stores user input
    while(!isValid(specialty, 1,6)){//validates the users answer to be only from the selected choices
        cout << "Please only choose a vaild answer";
        cin >> specialty;
    }

    cout << "\n";

    cout << "Hello Student please select which country do you want to go to?" <<endl;
    cout << "1. Mexico (Spanish)" <<endl;
    cout << "2. Brazil (Português)" <<endl;
    cout << "3. Cameroon (French and English)" <<endl;
    cout << "4. Ivory Coast (French)" <<endl;
    cout << "5. Egypt (Arabic)" <<endl;
    cout << "6. Morocco (Arabic)" <<endl;
    cout << "7. Phillippines(Taglog)" <<endl;
    cout << "8. France(French)" <<endl;
    cout << "9. Mozambique (Português)" <<endl;
    cout << "10. French Guiana(Spanish and French)" <<endl;



    cout << "Please choose a number 1-10: ";
    cin >> country;
    while(!isValid(country, 1,10)){
        cout << "Please only choose a vaild answer";
        cin >> country;
    }
    
    
    //display the probability of matching with each country within the program and displaying the country the user has the best chances of getting assinged
    probability( countries, languageMap[language],  specialityMap[specialty],  countryMap[country]);
    
    
    
    
    
    
    
    
    return 0;
}

void printCountries(vector<Country> countries){
    cout << "This is the Countires catalog along with their information and needed fields for the students" << endl << endl;
    vector<Country>::iterator start;
    for(start = countries.begin(); start!=countries.end(); start++)
    {
        cout << start->name << " language(s) spoken: ";
        vector<string>::iterator it;
        for(it = start->languages.begin(); it!= start->languages.end(); it++){
            cout << *it <<" ";
        }
        cout  << endl << "Speciality(ies) needed: ";
        for(it = start->specialties.begin(); it!= start->specialties.end(); it++)
        {
            if (it+1 == start->specialties.end())
            {
                cout << *it <<"";
            }
            else {
                cout << *it <<", ";

            }
        }
        
        
        cout <<endl << endl;
    }
}



void probability(vector<Country> countries, string language, string speciality, string country) {
    // Example data - replace this with your actual data
    
    
    
    // Assign weights to each matching preference
    float languageWeight = 0.5;  // Adjust weights as needed
    float specialtyWeight = 0.4;//split 1 into three numbers shared
    float countryweight = 0.1; //Added together must equal 1
    
    float userLanguage = 0;//user input varibles that scale the weight of each category
    float userSpeciality = 0;
    float userCountry = 0;
    float maxProb = 0.0;//varible to store the country with the highest probability of getting assigned to user based on responses
    string maxCountry;//varible to store the name of the country with the highest probability
   
    //user message how the probability to determined the user's country's match and assingment is calculated
    cout << endl << "Language is weighted at 50%, Specialty is weighted at 40%,\nFinally your countries preference is weighted at 10% for your overall match to each country" << endl<< endl;
                    
    

    vector<Country>::iterator start;//iterator to go through the countries vector and iterate through each country displayed to the user
    for(start = countries.begin(); start!=countries.end(); start++){
        
        vector<string>::iterator it = find(start->languages.begin(), start->languages.end(), language);//iterator to find if the language the user selected is spoken
        //within the current country the loop is iterating through
        if(*it == language){//if the language is spoken in the country
            userLanguage = 1.0/start->languages.size();//then userLanguage variable is update to store the value 1 divided by the amount of languages spoken in the country
            //since the user can speak 1 out of the x amount of languages the country speaks the weight language has on the probability is split by the amount of languages
            //spoken within the country
        
        }
        else{
            userLanguage = 0;//if the language is not found then userLanguage is 0; therefore the chances of the user mathcing to the current country are slim since language
            //accounts for half of the bearing in determing the users country match
        }
        
        //iterator to find if the specialty the user selected is needed within the current country the loop is iterating through
        vector<string>::iterator it2 = find(start->specialties.begin(), start->specialties.end(), speciality);
       
        if(*it2 == speciality){// if the specialty is needed
            userSpeciality = 1.0/start->specialties.size();// assigns userSpeciality how much of the speciality weight wil be used to determined the user's probability
            //to the current country, by dividing the speciality the user knows by the specialities needed by the current country
        }
        else{//however if the user's speciality is not needed within the current country
            userSpeciality = 0;//the weight of specialtiy will equal zero since the current country does not need the user's speciality thus it will
            //not be taken into account to calculate the country compatibility probability
        }
        
        
       //checks if the current country is the same the user answered
        if(country == start->name){
            userCountry = 1.0;//if so then assings userCountry to 1 allowing the full 10 percent of country weight to be accounted for with the probability equation
        }
        else{
            userCountry = 0;// if not then the 10 percent will not be taking into account since the user did not want to go to the current country
        }
        
        
        
        //calculates the probability of going to selected country based on user responses and the assinged weight of each category
        //each category has a weight which is split within language, speciality, and country prefernce. the weight varibles add to one since
        // since probability will always be between zero and one, the probability of a user going to a certain country will equal one as in 100
        //percent chance of going if they speak the only language they need, fufill the only speciality required, and willingly have that country as
        //their chosen preference; however if the country speaks two languages then the weight of lanuages is divied by two since the user only speaks one of
        // the two languages, same goes for speciality, and for country, whehter the user choose the certian country or not.
        float prob = ( languageWeight * userLanguage +  specialtyWeight * userSpeciality + countryweight * userCountry);
        
        //if the current coutry that the loop is iterating through has a greater probability then maxProp
        if(maxProb <= prob){
            maxProb = prob;//maxProp will equal the current probability of the current country and it will become the new maxProb
            maxCountry = start->name;//maxCoutry will be set to equal the coutry with the highest percentage compatibility
        }


         
       
        //print out the probability of going to each individual country based on user responses
        cout << "Chances of going to " << start->name << ": "<<(prob)*100 <<"%"<<endl;
    }
    //prints the country with the best percentage compatibility
    cout << endl<< "The Country you got matched based on percentage compatibility is " << maxCountry << endl;
       
        }



bool isValid(string &choice, int min, int max){
    //checks if answer is valid within a certain range
    bool validity = true;//variablie that determines whether the argument choice the user provided is valid
    for(char c: choice){//within every character of choice
        if(!isdigit(c)){//if there is a non-digit input
            validity= false;//then validity will equal to false and return
        }
    }
    if(validity){//if the user input is fully only digits and validity remains true then
        int num = stoi(choice);//creates a temp varible to convert choice from string to int form
        if ( !((num >= min)&&(num <= max)) )//checks if the number falls within selected range
        {
            validity =false;//if the number falls outisde the range, validity will equal false and return
        }
    }
    return validity;
}
