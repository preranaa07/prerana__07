int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int time = tickets[k];
 for (int i = 0; i < ticketsSize; i++) {
 if (i < k) {
 if (tickets[i] <= tickets[k]) {
 time += tickets[i];
 } else {
 time += tickets[k];
 }
 }
 else if (i > k) {
 if (tickets[i] < tickets[k]) {
 time += tickets[i];
 } else {
 time += (tickets[k] - 1);
 }
 }
 }
 return time;
    
}