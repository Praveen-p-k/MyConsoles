/* FINDING THE COUSIN'S FROM OUR'S RELATIONS
IF YOU ENTER ONE PERSON NAME, MY CODE WILL TELLS YOUR COUSIN'S FROM YOUR RELATION */

class Family {
    constructor (name, gender) {
        this.name = name;
        this.gender = gender;
        
        this.dad = null; //both points the 
        this.mom = null; // same person
        this.sibbling = null;
        this.child = null;
        this.next = null;
    }
}

let head = null, tail = null;
let got_match = 0;


const Check_return = (name, gender) => {
    let ptr = head;

    while (ptr != null) {
        if (ptr.name == name) {
            return ptr;
        }
        ptr = ptr.next;
    }

    ptr = new Family (name, gender) ;
    ptr.mom = ptr.dad = ptr.sibbling = ptr.child = ptr.next = null;
    
    if (head == null) {
        head = tail = ptr;
    }

    else {
        tail = tail.next = ptr;
    }
    return ptr;
}


const Push = (name, gender, mom, dad) => {
    
    let ptr;
    ptr     = Check_return (name, gender);
    ptr.mom = Check_return (mom, "female");
    ptr.dad = Check_return (dad, "male");

    
    //if the parent node child will be null, his child address will be given to that
    if (ptr.mom.child == null) {
        ptr.mom.child = ptr;
        ptr.dad.child = ptr;
        ptr.sibbling = null;
    }

    // remaining childs are pointed to sibblings only
    else {
        let append_sibbling = ptr.mom.child;
        
        while (append_sibbling.sibbling != null) {
            append_sibbling = append_sibbling.sibbling;
        }

        append_sibbling.sibbling = ptr;
        ptr.sibbling = null;
    }
}


//here i recieve grand parent address, with this I will easily find my matches

const Find_Patner = (grand, gender, self_gen) => {
    let ptr = grand.child;

    while (ptr != null) {
        if (ptr.gender != gender) {
            let current = ptr.child;

            while (current != null) {
                if (current.gender != self_gen) {
                    console.log (current.name);
                    got_match = 1;
                }
                current = current.sibbling;
            }
        }
        ptr = ptr.sibbling;
    }
}


const Find_match = (name) => {
    let ptr = head;

    while (ptr != null) {
        if (ptr.name == name) {
            break;
        }
        ptr = ptr.next;
    }

    //going to find cousin's from mother side
    if (ptr.mom && ptr.mom.mom) {
        Find_Patner (ptr.mom.mom, "female", ptr.gender);
    }

    //going to find cousin's from father side
    if (ptr.dad && ptr.dad.dad) {
        Find_Patner (ptr.dad.dad, "male", ptr.gender);
    }
}


//here we will the family circle
const Display = () => {
    tail = head;

    while (tail != null) {
        console.log ("Name    : " + tail.name);
        console.log ("Gender  : " + tail.gender);
        
        if (tail.mom != null)   console.log ("Mom     : " + tail.mom.name); 
        else    console.log ("Mom     : " +null);
        if (tail.dad != null)   console.log ("Dad     : " + tail.dad.name);   
        else    console.log ("Dad     : " + null);
        
        console.log ("\n\n");

        tail = tail.next;
    }
}


/* these all are one of the family entries, by using this we will find cousin's for any one */

Push ("Praveen", "male", "Sumathi", "Ramar");
Push ("Radhika", "female", "Sumathi", "Ramar");
Push ("Papa", "female", "Krishna Priya", "Praveen");
Push ("Baby", "female", "Radhika", "Sudhan");
Push ("thambi", "male", "Krishna Priya", "Praveen");
Push ("Ramar",   "male", "Valli",   "Solai");
Push ("Ramya",   "female", "Valli", "Solai");
Push ("Sumathi", "female", "Ponkodi", "Ramasamy");
Push ("Govindhan", "male", "Ponkodi", "Ramasamy");
Push ("Geetha", "female", "Ramya", "Karthick");
Push ("Kavi", "female", "Sangeetha", "Govindhan");
Push ("Prem Kumar", "male", "Ponkodi", "Ramasamy");
Push ("Krishna Priya", "female", "Sathya", "Prem Kumar");


console.log ("\n\nYour family Members are Mapped with Each other\n\n");
Display ();

console.log ("\n\nYour Matches Are ...");

//here i will given one name to find his cousin's from his circle 
Find_match ("thambi");

if (got_match == 0) {
    console.log ("No Matches Found");
}
