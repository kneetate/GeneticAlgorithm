#pragma once
#include <vector>
#include <iostream>
#include <random>
using namespace std;

class Individual
{
private:
    int GetIntegerRand(int min, int max);
    double GetDoubleRand(double min, double max);
    vector<double> Data;
    double Fitness;
public:
    Individual() {};
    Individual(vector<double> data)
    {
        Data = data;
    };
    Individual(double min, double max, int size)
    {
        for (int i = 0; i < size; i++)
        {
            Data.push_back(GetDoubleRand(min, max));
        }
    }
    void SetData(vector<double> data);
    void SetFitness(double fitness);
    vector<double> GetData();
    double GetFitness();
};

class GeneticAlgorithm
{
private:
    int MaxEpoc;
    int IndividualNum;
    double MutateRate;
    double SurviveRate;
    int GetIntegerRand(int min, int max);
    double GetDoubleRand(double min, double max);
    vector< Individual > CurrentGeneration;

    vector< Individual > Survive();
    vector< Individual > Select();
    void GenerationChange();
public:
    void Crossover(Individual Male, Individual Female, Individual& child_1, Individual& child_2);
    void Mutate(Individual Origin, Individual& Mutant);
    void InitGA(int maxepoc, int individualnum, vector<Individual> firstgene);
    Individual GetResult();
};