int roll(int max)
{
    int roll;
    roll = rand() % max + 1;
    return roll;
}
//上限为max的随机取值方法

srand(( unsigned int ) time (0));
srand(seed[s_count]);
//void srand(unsigned int seed);
//srand()为后续的rand()提供seed，使其基于此生成随机数
//在srand()之前使用rand(),seed默认设置为1