
#ifndef TALLER_MARVEL_CAPCOM_JSONSINTAX_H
#define TALLER_MARVEL_CAPCOM_JSONSINTAX_H

typedef struct JSON_checker_struct {
    int valid;
    int state;
    int depth;
    int top;
    int* stack;
} * JSON_checker;


extern JSON_checker new_JSON_checker(int depth);
extern int  JSON_checker_char(JSON_checker jc, int next_char);
extern int  JSON_checker_done(JSON_checker jc);
bool JsonIsValid(const char *file);

#endif //TALLER_MARVEL_CAPCOM_JSONSINTAX_H
