
let scan = require('prompt-sync')();

class Node {
    constructor (data) {
        this.data = data;
        this.next = null;
    };
} let head = tail = null;


const Push = (data) => {

    let newNode = new Node(data);
    if (!head)  head = tail = newNode;
    else    tail = tail.next = newNode;
}

const Display = () => {
    
    tail = head;
    
    while (tail) {
        console.log(tail.data);
        tail = tail.next;
    }
}

Main = () => {
    for (let i = 0; i < 10; i++) {
        Push(i + 1);
    }
    Display();
}

Main();
