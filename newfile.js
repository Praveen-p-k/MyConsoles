
let scan = require('prompt-sync')();

class Node {
    constructor (data) {
        this.data = data;
        this.next = null;
    };
} let head = tail = null;


const Push = () => {

    let newNode = new Node(data);

    if (!head)  head = tail = newNode;

    else    tail = tail.next = newNode;
}

const Display = () => {

    
}


for (let i = 0; i < 10; i++) {

    Push(i + 1);
}