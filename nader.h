extern char line[100];          // GPGGA line
extern int i;                   // iterator on the line
extern char* line_cutting[15];  // hn2t3 2l GPGGA line
extern int k = 0;               // iterator on the cutting line

void coordinates() {
    line[0] = '$';
    line[1] = 'G';
    line[2] = 'P';
    line[3] = 'G';
    line[4] = 'G';
    line[5] = 'A';
    while (1) {
        char c = readUART();
        i = 5;
        if (c == '$') {
            c = readUART();
            if (c == 'G') {
                c = readUART();
                if (c == 'P') {
                    c = readUART();
                    if (c == 'G') {
                        c = readUART();
                        if (c == 'G') {
                            c = readUART();
                            if (c == 'A') {
                                c = readUART();
                                while (c != '\n') {
                                    line[i++] = c;
                                    c = readUART(); }
                                break; }}}}}}}
                                
                                
                                
                                
                                
                                
                                
                                
                                
