#include <stdio.h>

//function to convert metrics 
int K_M(char c);   //conversions between km and m
int Kg_P(char c);  //conversio between kg and pound
int Cm_In(char c); // cm and in
int C_F(char c);   //celcius and farehenheight


int main(){
        int input; // the input from the user number wise
        char quit; //input from user if q or Q to quit

        //prompt user for input
        printf("Please enter the number or character for corresponding actions: \n\n 1: Kilometer and Miles \n 2: for Kilogram and Pound \n 3: for Centimeter and Inch \n 4: Celsius and Fahrenheit \n q or Q: for quit \n");

        printf("please enter corresponding value:");

        //scan data from user to process value ( using address-of operator)
        scanf("%d,%c", &input, &quit);
        //if (quit == 'Q' || quit == 'q'){
        //      printf("program terminated.");
        //      return;
        //}
        //while loop to make sure inputs are cases 1 to 4
        while(input == 1 || input == 2 || input ==3 || input ==4){

            switch(input){
                    //cases 1 to 4
                    case 1: //km to m
                            K_M(input);
                            break;
                    case 2: //kg and punds
                            Kg_P(input);
                            break;
                    case 3: //cm and in
                            Cm_In(input);
                            break;
                    case 4: //celcuis to farenheight
                            C_F(input);
                            break;
                    default:
                            printf("\n the input was invald please enter 1,2,3,4q or Q");
                            return main(); //for all other values repeat program
                            printf("Please enter the number or character for corresponding actions: \n\n 1: Kilometer and Miles \n 2: for Kilogram and Pound \n 3: for Centimeter and Inch \n 4: Celsius and Fahrenheit \n q or Q: for quit \n");
            printf("\n enter corresponding value (char or int): ");

            scanf("%d",&input);
            }
        printf("Program terminated.\n");
        return 0;

        }
}
//Km and Mile
int K_M(char input){
        char choice; //char input from user K or M in this case

        //ask for direction of conversion
        printf("K for Kilometer to Mile \nM for Mile to Kilometer\n");
        printf("Enter your choice: ");

        //get user info
        scanf(" %c", &choice);

        switch(choice){
                double ans; // calculation of conversion
                float v; //value 
                case 'K':
                        printf("\nEnter value in Kilomenter: ");
                        scanf("%f",&v); //get data
                        //the conversion km to mile = km/1.609344)
                        ans = v/1.609344;
                        printf("\nThe value in Miles is %f\n",ans);
                        break;
                case 'M':
                        printf("\nEnter value in Miles: ");
                        scanf("%f",&v); //get data
                        //the conversion mile to km = m(1.609344)
                        ans = v * 1.609344;
                        printf("\nThe value in Kilometer is %f\n",ans);
                        break;
                default:
                        printf("\n Input not valid please enter M or K: ");
                        scanf("%c",&choice);
                        return K_M(choice); // run through program again
        }
return 0;
}
//Pound to Kilogram
int Kg_P(char input){
        char choice; //char input from user K or M in this case

        //ask for direction of conversion
        printf("K for Kilogram to pound \nP for Pound to  Kilogram\n");
        printf("Enter your choice: ");

        //get user info
        scanf(" %c", &choice);

        switch(choice){
                double ans; // calculation of conversion
                float v; //value 
                case 'K':
                        printf("\nEnter value in Kilogram: ");
                        scanf("%f",&v); //get data
                        //the conversion kg to pound = kg * 2.20462
                        ans = v* 2.20462;
                        printf("\nThe value in Pounds is %f\n",ans);
                        break;
                case 'P':
                        printf("\nEnter value in Pounds: ");
                        scanf("%f",&v); //get data
                        //the conversion = P/ 2.20462
                        ans = v/2.20462;
                        printf("\nThe value in Kilograms is %f\n",ans);
                        break;
                default:
                        printf("\n Input not valid please enter K or P: ");
                        scanf("%c",&choice);
                        return Kg_P(choice); // run through program again
        }
return 0;
}
//Centimeter to inch
int Cm_In(char input){
        char choice; //char input from user K or M in this case

        //ask for direction of conversion
        printf("C for Centimeter to Inch \nI for Inch to Centimeter\n");
        printf("Enter your choice: ");

        //get user info
        scanf(" %c", &choice);

        switch(choice){
                double ans; // calculation of conversion
                float v; //value
                case 'C':
                        printf("\nEnter value in Centimeter: ");
                        scanf("%f",&v); //get data
                        //the conversion= cm/2.54
                        ans = v/2.54;
                        printf("\nThe value in Inches is %f\n",ans);
                        break;
                case 'I':
                        printf("\nEnter value in Inches: ");
                        scanf("%f",&v); //get data
                        //the conversion = in * 2.54
                        ans = v * 2.54;
                        printf("\nThe value in Centimeter is %f\n",ans);
                        break;
                default:
                        printf("\n Input not valid please enter C or I: ");
                        scanf("%c",&choice);
                        return Cm_In(choice); // run through program again
        }
return 0;
}

//Celcius to Farenheight
int C_F(char input){
        char choice; //char input from user K or M in this case

        //ask for direction of conversion
        printf("C for Celcius to Fahrenheit \nF for Fahrenheit to Celcius\n");
        printf("Enter your choice: ");

        //get user info
        scanf(" %c", &choice);

        switch(choice){
                double ans; // calculation of conversion
                float v; //value 
                case 'C':
                        printf("\nEnter value in Celcius: ");
                        scanf("%f",&v); //get data
                        //the conversion = ((c/5)*9)+32
                        ans = ((v/5)*9)+32;
                        printf("\nThe value in Fahrenheit is %f\n",ans);
                        break;
                case 'F':
                        printf("\nEnter value in Fahrenheit: ");
                        scanf("%f",&v); //get data
                        //the conversion = ((f-32)*5)/9
                        ans = ((v-32)*5)/9;
                        printf("\nThe value in Celcius is %f\n",ans);
                        break;
                default:
                        printf("\n Input not valid please enter C or F: ");
                        scanf("%c",&choice);
                        return C_F(choice); // run through program again
        }
return 0;
}
