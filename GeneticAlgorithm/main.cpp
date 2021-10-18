#include "GeneticAlgorithm.h"

double ObjectFunction(vector<double> data)
{
	double x = data[0];
	double y = data[1];
	return (x - 4) * (x - 4) + (y - 5) * (y - 5);
}

vector<Individual> Sort(vector<Individual> Origin,bool isAscending)
{
	vector<Individual> Sorted = Origin;
	int calc_times = Origin.size() * (Origin.size() - 1) / 2;
	for (int i = 0; i < calc_times; i++)
	{
		for (int j = 0; j < Origin.size() - 1; j++)
		{
			if (Sorted[j].GetFitness() < Sorted[j + 1].GetFitness())
			{
				Individual tmp_small = Sorted[j];
				Individual tmp_large = Sorted[j + 1];
				Sorted[j] = tmp_large;
				Sorted[j + 1] = tmp_small;
			}
		}

	}
	if (isAscending)
	{
		reverse(Sorted.begin(), Sorted.end());
	}
	
	return Sorted;
}

vector<double> GA()
{
	int epoc = 50;
	double max = 10;
	double min = -10;
	int size = 2;
	int population = 20;
	int survive = 9;
	int mutation = 1;
	int mating = 10;

	GeneticAlgorithm ga;
	vector<Individual> First;
	for (int i = 0; i < population; i++)
	{
		Individual tmp(min, max, size);
		tmp.SetFitness(ObjectFunction(tmp.GetData()));
		First.push_back(tmp);
	}
	vector<Individual> CurrentGeneration = First;

	for (int i = 0; i < epoc; i++)
	{
		vector<Individual> tmp;
		vector<Individual> half;
		CurrentGeneration = Sort(CurrentGeneration,true);
		for (int k = 0; k < population / 2; k++)
		{
			half.push_back(CurrentGeneration[k]);
		}
		CurrentGeneration = half;
		for (int k = 0; k < population / 2; k++)
		{
			CurrentGeneration.push_back(half[k]);
		}

		while (CurrentGeneration.size() > population)
		{
			CurrentGeneration.pop_back();
		}

	
		for (int j = 0; j < population;j++)
		{
			/*if (j <= mating)
			{
				if (j % 2 != 0)
				{
					Individual child1;
					Individual child2;
					ga.Crossover(CurrentGeneration[j], CurrentGeneration[j - 1], child1, child2);
					tmp.push_back(child1);
					tmp.push_back(child2);
				}
			}
			else if (j > mating && j <= mating + mutation)
			{
				Individual mutant;
				ga.Mutate(CurrentGeneration[j], mutant);
				tmp.push_back(mutant);
			}
			else
			{
				tmp.push_back(CurrentGeneration[i]);
			}*/
			if (j  < population / 2)
			{
				tmp.push_back(CurrentGeneration[j]);
			}
			else if(j == 19)
			{
				Individual mutant;
				ga.Mutate(CurrentGeneration[j], mutant);
				tmp.push_back(mutant);
			}
			else
			{
				if (j % 2 != 0)
				{
					Individual child1;
					Individual child2;
					ga.Crossover(CurrentGeneration[j], CurrentGeneration[j - 1], child1, child2);
					tmp.push_back(child1);
					tmp.push_back(child2);
				}
			}
		}

		for (int i = 0; i < tmp.size(); i++)
		{
			tmp[i].SetFitness(ObjectFunction(tmp[i].GetData()));
		}
		CurrentGeneration.clear();
		CurrentGeneration = tmp;
		cout << "Epoc " << i;
		cout << " Answer is ..." << CurrentGeneration[0].GetData()[0] << " , " << CurrentGeneration[0].GetData()[1];
		cout << " Cost is ..." << CurrentGeneration[0].GetFitness() << endl;
	}
	CurrentGeneration = Sort(CurrentGeneration,true);
	return CurrentGeneration[0].GetData();
}


int main()
{
	GA();
	return 1;
}