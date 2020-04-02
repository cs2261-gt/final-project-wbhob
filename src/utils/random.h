#ifndef RANDOM_H
#define RANDOM_H

#define RANDOM_RANGE(lower, upper) ((rand() / ((upper) - (lower))) + (lower))
#define RANDOM(upper) ((rand() / (upper)))

#endif