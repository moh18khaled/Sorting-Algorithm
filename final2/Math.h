

#ifndef MATH_H_
#define MATH_H_

#define SET_BIT(REG,BIT) (REG|=(1<<BIT))
#define GET_BIT(REG,BIT) ((REG>>BIT) & 1)
#define CLR_BIT(REG,BIT) (REG&=~(1<<BIT))
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))



#endif /* MATH_H_ */