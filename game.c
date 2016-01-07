int decide_move(int num, int potential_pieces) {
    if(num % (potential_pieces + 1) == 0) {
        //we've lost if the other player knows what they're doing
        return (num % (potential_pieces + 13)) % potential_pieces + 1; //just pick something, not important
    } else {
        return num % (potential_pieces + 1);
    }
}
