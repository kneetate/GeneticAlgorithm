#include "GeneticAlgorithm.h"

void Individual::SetData(vector<double> data)
{
    Data = data;
}
void Individual::SetFitness(double fitness)
{
    Fitness = fitness;
}

vector<double> Individual::GetData()
{
    return Data;
}

double Individual::GetFitness()
{
    return Fitness;
}

void GeneticAlgorithm::InitGA(int maxepoc, int indnum, vector<Individual> firstgene)
{
    MaxEpoc = maxepoc;
    IndividualNum = indnum;
    CurrentGeneration = firstgene;
    IndividualNum = firstgene.size();
}

void GeneticAlgorithm::Crossover(Individual Male, Individual Female, Individual& Child_1, Individual& Child_2)
{
    //2-point mating
    int element_num = Male.GetData().size();
    int first_point = GetIntegerRand(0, element_num - 1);
    int second_point = GetIntegerRand(0, element_num - 1);
    vector<double> child1_data;
    vector<double> child2_data;
    vector<double> MaleData = Male.GetData();
    vector<double> FemaleData = Female.GetData();
    child1_data.reserve(element_num);
    child2_data.reserve(element_num);
    for (int i = 0; i < element_num; i++)
    {
        if (i <= first_point)
        {
            child1_data.push_back(MaleData[i]);
            child2_data.push_back(FemaleData[i]);
        }
        else if (i > first_point && i <= second_point)
        {
            child1_data.push_back(FemaleData[i]);
            child2_data.push_back(MaleData[i]);
        }
        else
        {
            child1_data.push_back(MaleData[i]);
            child2_data.push_back(FemaleData[i]);
        }
    }
    Child_1.SetData(child1_data);
    Child_2.SetData(child2_data);
}

void GeneticAlgorithm::Mutate(Individual Origin, Individual& Mutant)
{
    vector<double> OriginData = Origin.GetData();
    reverse(OriginData.begin(), OriginData.end());
    Mutant.SetData(OriginData);
}


int Individual::GetIntegerRand(int min, int max)
{
    static std::mt19937_64 mt64(0);

    // [min_val, max_val] の一様分布整数 (int) の分布生成器
    std::uniform_int_distribution<uint64_t> get_rand_uni_int(min, max);

    // 乱数を生成
    return get_rand_uni_int(mt64);
}

double Individual::GetDoubleRand(double min, double max)
{
    static std::mt19937_64 mt64(0);

    // [min_val, max_val] の一様分布整数 (int) の分布生成器
    std::uniform_real_distribution<double> get_rand_uni_real(min, max);

    // 乱数を生成
    return get_rand_uni_real(mt64);
}

int GeneticAlgorithm::GetIntegerRand(int min, int max)
{
    static std::mt19937_64 mt64(0);

    // [min_val, max_val] の一様分布整数 (int) の分布生成器
    std::uniform_int_distribution<uint64_t> get_rand_uni_int(min, max);

    // 乱数を生成
    return get_rand_uni_int(mt64);
}

double GeneticAlgorithm::GetDoubleRand(double min, double max)
{
    static std::mt19937_64 mt64(0);

    // [min_val, max_val] の一様分布整数 (int) の分布生成器
    std::uniform_real_distribution<double> get_rand_uni_real(min, max);

    // 乱数を生成
    return get_rand_uni_real(mt64);
}