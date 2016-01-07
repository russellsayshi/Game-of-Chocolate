int decide_move(int num) {
    if(num % 5 == 0) {
        //we've lost if the other player knows what they're doing
        return (num % 13) % 4 + 1; //just pick something, not important
    } else {
        return num % 5;
    }
}
