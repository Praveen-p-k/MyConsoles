#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define set_cursor(x, y) printf("\033[%d;%dH", y, x)



/***********************************************************************************************************************************************/
/* THIS ARE THE MAIN FUNCTIONS USED IN IT... */


void Book_Tickets () ;

void Cancellation () ;

void Overall_Summary () ;

void View_Seatings () ;

void Booking_Summary () ;



/***********************************************************************************************************************************************/
/* THIS STRUCTURE FOR THE SEATING ARRANGEMENTS  */


struct Seating_arrangements 
{
    int Timing [3][16] ;
    
} ptr [3] ;  



/***********************************************************************************************************************************************/
/* THIS STRUCTURE FOR STORING THE DETAILS OF EACH BOOKING OCCURED */


struct Booking_stores
{
    int seats_allocated [16] ;
    
    int screen [2] ;
    
    int Class ;
    
    float Ticket_price ;
    
    float Discount [2] ;
    
    float Total_amt ;
    
} ttr [50] ;



int time1, screen, Class, up ;

int Booking_Id = 0 ;

float Kalla_Petti ;




/**********************************************************************************************************************************************/
/* FINDING DISCOUNTS FOR YOUR COUPON */


int find_discount (char Coupon [], int Ticket_price)
{
    float Discount, price = Ticket_price ;
    
    if (strcmp (Coupon, "D10") == 0)
    {
        Discount = 0.1 * price ;
    }
    
    else
    if (strcmp (Coupon, "D20") == 0)
    {
        Discount = 0.2 * price ;
    }
    
    else
    if (strcmp (Coupon, "D30") == 0)
    {
        Discount = 0.3 * price ;
    }
    
    else
    {
        Discount = 0 ;
    }
    
    return Discount ;
}



/**********************************************************************************************************************************************/
/*  TICKETS FILLING BASED ON THE SCREEN  YOU ARE CHOOSING */


void To_find_Screen (int choice)
{
    if (choice == 1 || choice == 2 || choice == 5 || choice == 6)
    {
        time1 = 1 ;
        
        if (choice % 2 == 0)
        {
            Class = 2 ;
        }
        
        else
        {
            Class = 1 ;
        }
    }
    
    else
    {
        time1 = 2 ;
        
        if (choice % 2 == 0)
        {
            Class = 2 ;
        }
        
        else
        {
            Class = 1 ;
        }
    }
}


/********************************************************************************************************************************************/
/*  DISPLAY THE SCREEN's TIMING's, SEAT's AVAILABILITY AND SHOWS THE CLASS's */


int Display_Screen ()

{
    int choice ;
    
    printf ("\n 1. Screen 1 : 4 PM : 5 Seats(First Class) ") ;
       
    printf ("\n 2. Screen 1 : 4 PM : 10 Seats(Second Class) ") ;
       
    printf ("\n 3. Screen 1 : 8 PM : 5 Seats(First Class) ") ;
       
    printf ("\n 4. Screen 1 : 8 PM : 10 Seats(Second Class) ") ;
       
    printf ("\n 5. Screen 2 : 4 PM : 5 Seats(First Class) ") ;
       
    printf ("\n 6. Screen 2 : 4 PM : 10 Seats(Second Class) ") ;
       
    printf ("\n 7. Screen 2 : 8 PM : 5 Seats(First Class) ") ;
       
    printf ("\n 8. Screen 2 : 8 PM : 10 Seats(Second Class) \n\n") ;
    
    printf ("\n\n Enter the Choice (1/2/3/4/5/6/7/8) : ") ;
    
    scanf ("%d", &choice) ;
    
    if (choice > 4)
    {
        screen = 2 ;
    }
    
    else
    {
        screen = 1 ;
    }
    
    To_find_Screen (choice) ;
}


/*********************************************************************************************************************************************/
/*   OVERALL SEATING ARRANGEMENTS IN EACH SCREEN */


void View_Seatings ()
{
    do 
    {
        printf ("\n IN SCREEN 1 -> TIME 4 \n\n('MOVIE : THIRUCHITRAMBALAM')\n\n") ;
        
        for (int i=1; i<=15; i++)
        {
            printf ("%3d ", ptr [1]. Timing [1][i]) ;
            
            if (i % 5 == 0)
            {
                printf ("\n") ;
            }
        }
        
        printf ("\n IN SCREEN 1 -> TIME 8 \n\n('MOVIE : THIRUCHITRAMBALAM')\n\n") ;
        
        for (int i=1; i<=15; i++)
        {
            printf ("%3d ", ptr [1]. Timing [2][i]) ;
            
            if (i % 5 == 0)
            {
                printf ("\n") ;
            }
        }
        
        printf ("\n IN SCREEN 2 -> TIME 4 \n\n('MOVIE : VIRUMAN')\n\n") ;
        
        for (int i=1; i<=15; i++)
        {
            printf ("%3d ", ptr [2]. Timing [1][i]) ;
            
            if (i % 5 == 0)
            {
                printf ("\n") ;
            }
        }
        
        printf ("\n IN SCREEN 2 -> TIME 8 \n\n('MOVIE : VIRUMAN')\n\n") ;
        
        for (int i=1; i<=15; i++)
        {
            printf ("%3d ", ptr [2]. Timing [2][i]) ;
            
            if (i % 5 == 0)
            {
                printf ("\n") ;
            }
        }
    }   while (0) ;
}



/********************************************************************************************************************************************/
/* CHECK IF SEATS AVAILABLE OR NOT */


int check_availability (int Tickets)
{
    int counting = 0 ;
    
    if (Class == 1)
    {
        for (int i=1; i<=5; i++)
        {
            if (ptr [screen]. Timing [time1][i] == 0)
            {
                ++counting ;
            }
        }
    }
    
    else
    {
        for (int i=6; i<=15; i++)
        {
            if (ptr [screen]. Timing [time1][i] == 0)
            {
                ++counting ;
            }
        }
    }
    
    if (Tickets <= counting)
    {
        return 0 ;
    }
    
    else
    {
        return -1 ;
    }
}



/*******************************************************************************************************************************************/
/*  TICKET BOOKING */


void Book_Tickets (int Tickets) 
{
    char Coupon [5] ;
    
    up = 0 ;
    
    int get ;
    
    float price = Tickets ;
    
    get = check_availability (Tickets) ;
    
    if (get == 0)
    {
        printf ("\n\n >> ********* VALID COUPON's (D10, D20, D30) ********* >>\n") ;
        
        printf ("\n Do You Have a Coupon if have Enter Else 0 : ") ;
    
        scanf ("%s", Coupon) ;
        
        if (Class == 1)
        {
            for (int i=1; i<=5; i++)
            {
                if (ptr [screen]. Timing [time1][i] == 0)
                {
                    ptr [screen]. Timing [time1][i] = 1 ;
                    
                    ttr [Booking_Id]. seats_allocated [++up] = i ;
                    
                    if (--Tickets == 0)
                    {
                        break ;
                    }
                }
            }
        }
        
        else
        {
            for (int i=6; i<=15; i++)
            {
                if (ptr [screen]. Timing [time1][i] == 0)
                {
                    ptr [screen]. Timing [time1][i] = 1 ;
                    
                    ttr [Booking_Id]. seats_allocated [++up] = i ;
                    
                    if (0 == --Tickets)
                    {
                        break ;
                    }
                }
            }
        }
        
        ttr [Booking_Id]. screen [0] = screen ;
        
        ttr [Booking_Id]. screen [1] = (time1 == 1) ? (4) : (8) ;
        
        ttr [Booking_Id]. Class = Class ;
        
        ttr [Booking_Id]. Ticket_price = (Class % 2 == 0) ? (100 * price) : (120 * price) ;
        
        ttr [Booking_Id]. Discount [0] = find_discount (Coupon, ttr [Booking_Id]. Ticket_price) ;
        
        get = atoi (& Coupon [1]) ;
        
        ttr [Booking_Id]. Discount [1] = get ;
        
        ttr [Booking_Id]. Total_amt = ttr [Booking_Id]. Ticket_price - ttr [Booking_Id]. Discount [0] ;
        
        Kalla_Petti += ttr [Booking_Id]. Total_amt ;
        
        Booking_Summary () ;
    }
    
    else
    {
        --Booking_Id ;
        
        printf ("\n\n                                >> Currnetly Not Available !! <<                             \n\n") ;
    }
    
    
}


/*****************************************************************************************************************************************/
/* TO VIEW THE DETAILS OF INDIVIDUAL BOOKING ID'S */



void Booking_Summary () 
{
    int Book_id = Booking_Id, incre = 0 ;

    
    printf ("\n\n BOOKING_ID %d\n", Book_id) ;
    
    printf ("\n Seats Allocated     :   ") ;
    
    if (ttr [Book_id]. Class == 1)
    {
        for (int i=1; i<=5; i++)
        {
            if (ttr [Book_id]. seats_allocated [++incre] != 0)
            {
                printf ("%d ", ttr [Book_id]. seats_allocated [incre]) ;
            }
        }
    }
    
    else
    {
        for (int i=6; i<=15; i++)
        {
            if (ttr [Book_id]. seats_allocated [++incre] != 0)
            {
                printf ("%d ", ttr [Book_id]. seats_allocated [incre]) ;
            }
        }
    }
    
    printf ("\n Movie               :  %s", ((ttr [Book_id]. screen [0] == 1) ? ("'THIRUCHITRAMBALAM'") : ("'VIRUMAN'"))) ;
    
    printf ("\n Screen %d            :   %d PM", ttr [Book_id]. screen [0], ttr [Book_id]. screen [1]) ;
    
    printf ("\n Ticket Price        :   %.2f", ttr [Book_id]. Ticket_price) ;
    
    if (ttr [Book_id]. Discount [1] != 0.00)
    {
        printf ("\n Discount %.0f -/-     :   %.2f",ttr [Book_id]. Discount [1], ttr [Book_id]. Discount [0]) ;
    }
            
    else
    {
        printf ("\n Discount %.0f -/-      :   %.2f",ttr [Book_id]. Discount [1], ttr [Book_id]. Discount [0]) ;
    }
    
    printf ("\n Total Amount        :   %.2f\n\n", ttr [Book_id]. Total_amt) ;
}



/******************************************************************************************************************************************/
/* TO CHECK THE ID IS CANCELLED OR NOT */


int To_Check_ID_Canceled_Or_Not (int Id)
{
    int flag = 0 ;
    
    int i = Id, incre = 0 ;
    
    if (ttr [i]. Class == 1)
    {
        for (int j=1; j<=5; j++)
        {
            if (ttr [i]. seats_allocated [++incre] != 0)
            {
                flag = 1 ;
            }
        }
    }
        
    else
    {
        for (int j=6; j<=15; j++)
        {
            if (ttr [i]. seats_allocated [++incre] != 0)
            {
                flag = 1 ;
            }
        }
    }
    
    return flag ;
}


/*****************************************************************************************************************************************/
/*  TO MAKE THE VIEW OF ALL BOOKING DETAILS IN OUR THEATER */


void Overall_Summary ()
{
    int flag ;
    
    printf ("\n") ;
    
    for (int i=1; i<=Booking_Id; i++)
    {
        int incre = 0 ;
        
        printf ("\n BOOKING_ID %d\n", i) ;
        
        
        flag = To_Check_ID_Canceled_Or_Not (i) ;
        
        if (flag == 1)
        {
            printf ("\n Seats Allocated     :   ") ;
            
            if (ttr [i]. Class == 1)
            {
                for (int j=1; j<=5; j++)
                {
                    if (ttr [i]. seats_allocated [++incre] != 0)
                    {
                        printf ("%d ", ttr [i]. seats_allocated [incre]) ;
                    }
                }
            }
            
            else
            {
                for (int j=6; j<=15; j++)
                {
                    if (ttr [i]. seats_allocated [++incre] != 0)
                    {
                        printf ("%d ", ttr [i]. seats_allocated [incre]) ;
                    }
                }
            }
            
            printf ("\n Movie               :  %s", ((ttr [i]. screen [0] == 1) ? ("'THIRUCHITRAMBALAM'") : ("'VIRUMAN'"))) ;
                
            printf ("\n Screen %d            :   %d PM", ttr [i]. screen [0], ttr [i]. screen [1]) ;
                
            printf ("\n Ticket Price        :   %.2f", ttr [i]. Ticket_price) ;
                
            if (ttr [i]. Discount [1] != 0.00)
            {
                printf ("\n Discount %.0f -/-     :   %.2f",ttr [i]. Discount [1], ttr [i]. Discount [0]) ;
            }
                
            else
            {
                printf ("\n Discount %.0f -/-      :   %.2f",ttr [i]. Discount [1], ttr [i]. Discount [0]) ;
            }
                
            printf ("\n Total Amount        :   %.2f\n\n\n", ttr [i]. Total_amt) ;
        }
        
        else
        {
            printf ("\n This BOOKING_ID Was Cancelled !\n\n") ;
        }
    }
}



/*****************************************************************************************************************************************/
/* BOOKING CANCELLATION PROCESS */


void Cancellation () 
{
    int cancel_id ;
    
    
    printf ("\nEnter the 'BOOKING ID'  you Want to CANCEL   : ") ;
    
    scanf ("%d", & cancel_id) ;
    
    int cls, screen, times, go = 0 ;
    
    float Tic_price ;
    
    cls = ttr [cancel_id]. Class ;
    
    screen = ttr [cancel_id]. screen [0] ;
    
    times = (ttr [cancel_id]. screen [1] == 4) ? (1) : (2) ;
    
    
    if (cancel_id <= Booking_Id)
    {
        printf ("\n\n BOOKING ID %d was Cancelled\n", cancel_id) ;
        
        printf ("\n Allocated Seats Are Now Cancelled      : ") ;
        
        if (cls == 1)
        {
            for (int i=1; i<=5; i++)
            {
                if (ttr [cancel_id]. seats_allocated [++go] != 0)
                {
                    printf ("%d ", ttr [cancel_id]. seats_allocated [go]) ;
                    
                    ptr [screen]. Timing [times][ ttr [cancel_id]. seats_allocated [go] ] = 0 ;
                    
                    ttr [cancel_id]. seats_allocated [go] = 0 ;
                }
            }
        }
        
        else
        {
            for (int i=6; i<=15; i++)
            {
                if (ttr [cancel_id]. seats_allocated [++go] != 0)
                {
                    printf ("%d ", ttr [cancel_id]. seats_allocated [go]) ;
                    
                    ptr [screen]. Timing [times][ ttr [cancel_id]. seats_allocated [go] ] = 0 ;
                    
                    ttr [cancel_id]. seats_allocated [go] = 0 ;
                }
            }
        }
        
        Tic_price = ttr [cancel_id]. Total_amt - (0.2 * ttr [cancel_id]. Total_amt) ;
        
        printf ("\n Total Amount You Paid For All Tickets  : %.2f", ttr [cancel_id]. Total_amt) ;
        
        printf ("\n COMMISSION FOR CANCELLATION (20 -/-)   : %.2f", (0.2 * ttr [cancel_id]. Total_amt)) ;
        
        printf ("\n Returned Amount                        : %.2f\n", Tic_price) ;
    }
    
    else
    {
        printf ("\n\nYour Entered A Wrong ID\n\nPlease Enter the Correct ID\n") ;
    }
    
    printf ("\n\n") ;
}



/*****************************************************************************************************************************************/
/* WELCOME    I      COME    */


int main ()
{
    int Choice ;
    
    printf ("\n\n                                 WELCOME   TO    DV__DHANUSH__VERIYAN's     THEATER\n\n") ;
    
    do
    {
        printf ("\n 1. For Booking         2. For Cancellation            3.For Overall Booking Summary        4.View Seating Arrangements          5. Exit \n\n") ; 
        
        printf (" Enter the Choice : ") ;
        
        scanf ("%d", & Choice) ;
        
        if (Choice == 1)
        {
            ++Booking_Id ;
            
            int Class, No_of_tic ;
            
            printf ("\n Enter No of Tickets : ") ;
            
            scanf ("%d", & No_of_tic) ;
        
            Display_Screen () ;
            
            Book_Tickets (No_of_tic) ;
        }
        
        else
        if (Choice == 2)
        {
            if (Booking_Id > 0)
            {
                Cancellation () ;
            }
            
            else
            {
                printf ("\n\nNo Booking is Recieved.......\n\n.........Please Book the Tickets First \n\n") ;
            }
        }
        
        else
        if (Choice == 3)
        {
            if (Booking_Id > 0)
            {
                Overall_Summary () ;
            }
            
            else
            {
                printf ("\n\nNo Booking is Recieved.......\n\n.......Please Book the Tickets First \n\n") ;
            }
        }
        
        else
        if (Choice == 4)
        {
            View_Seatings () ;
        }
        
        else
        {
            printf ("\n\n ********************* ... 'THANK_YOU_FOR_VISITING' !! ... **********************   \n\n\n                  DV__DHANUSH__VERIYAN's    THEATER \n \n\n **************************** ... 'VISTI_AGAIN' ... *****************************\n") ;
            
            return 0 ;
        }
        
    } while (1) ;
}


