#ifndef __PULPISSIMO_UTILS_H
#define __PULPISSIMO_UTILS_H

#define SET_BIT(REG, BIT)     ((REG) |= (1U << (BIT)))
#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(1U << (BIT)))
#define READ_BIT(REG, BIT)    ((REG) & (1U << (BIT)))
#define WRITE_BIT(REG, BIT, VAL)  ((REG) = ((REG) & ~(1U << (BIT))) | ((VAL) << (BIT)))

#define MODIFY_REG(REG, BIT, VAL)  ((REG) = ((REG) & ~(1U << (BIT))) | ((VAL) << (BIT)))
#define TOGGLE_BIT(REG, BIT)   ((REG) ^= (1U << (BIT)))

#endif
