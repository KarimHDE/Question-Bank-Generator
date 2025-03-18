#include <iostream>
#include <cstdlib>
using namespace std;

enum quizlevel { easy = 1, med = 2, hard = 3, mixlevel = 4 };
enum opetype { add = 1, sub = 2, mul = 3, divoperation = 4, mixtype = 5 };
struct describtion {
	int num_of_questions;
	quizlevel level_Of_Quiz;
	opetype type_of_questions;
	char YorN;
};
struct container {
	int result;
	int UserAnswer;
	int right;
	int wrong;
};

string levelToString(quizlevel level)
{
	switch (level)
	{
	case easy:
		return "Easy";
	case med:
		return "Medium";
	case hard:
		return "Hard";
	case mixlevel:
		return "Mix";
	default:
		return "Unknown";
	}
}
string typeToString(opetype type)
{
	switch (type)
	{
	case add:
		return "Add";
	case sub:
		return "Sub";
	case mul:
		return "Multiplication";
	case divoperation:
		return "div";
	case mixtype:
		return "mix";
	default:
		return "Unknown";
	}
}

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

int userAnswer()
{

	int answer;
	cin >> answer;
	return answer;
}

int NumberOf()
{
	int num;
	cin >> num;
	return num;
}

quizlevel levelOfQuestions()
{
	return (quizlevel)NumberOf();
}

opetype typeOfQuestions()
{
	return (opetype)NumberOf();
}

describtion QuizForm()
{
	describtion quizForm;
	cout << "How many questions do you want to answer ?" << endl;
	quizForm.num_of_questions = NumberOf();
	cout << "Enter Quiz level: [1] Easy, [2] Med, [3] Hard, [4] Mix " << endl;
	quizForm.level_Of_Quiz = levelOfQuestions();
	cout << "Enter Type of questions: [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix " << endl;
	quizForm.type_of_questions = typeOfQuestions();
	return  quizForm;
}

void checkAnswer(int num1, int num2, opetype type, container& info)
{
	switch (type)
	{
	case add:
		info.result = num1 + num2;
		break;
	case sub:
		info.result = num1 - num2;
		break;
	case mul:
		info.result = num1 * num2;
		break;
	case divoperation:
		if (num2 != 0)
			info.result = num1 / num2;
		else
		{
			cout << "Cannot divide by zero." << endl;
			return;
		}
		break;
	default:
		cout << "Invalid operation type!" << endl;
		return;
	}

	info.UserAnswer = userAnswer();

	if (info.result == info.UserAnswer)
	{
		system("color 2F");
		cout << "\tRight Answer :)" << endl;
		info.right++;
	}
	else
	{
		system("color 4F");
		cout << "\tWrong answer, the right answer is: " << info.result << endl;
		info.wrong++;
	}
}

void show_question(int num1, int num2, describtion quizform, container& info)
{
	if (quizform.type_of_questions == mixtype)
	{

		// ÇÎÊíÇÑ ÚãáíÉ ÚÔæÇÆíÉ Èíä ÌãÚ æØÑÍ æÖÑÈ æÞÓãÉ
		opetype randomOp = (opetype)RandomNumber(1, 4); // ÇÎÊÇÑ ÚãáíÉ ÚÔæÇÆíÉ

		switch (randomOp)
		{
		case add:
			cout << "\n" << num1 << "\n  + \n" << num2 << "\n__________\n";
			checkAnswer(num1, num2, randomOp, info);
			break;
		case sub:
			cout << "\n" << num1 << "\n  - \n" << num2 << "\n__________\n";
			checkAnswer(num1, num2, randomOp, info);
			break;
		case mul:
			cout << "\n" << num1 << "\n  * \n" << num2 << "\n__________\n";
			checkAnswer(num1, num2, randomOp, info);
			break;
		case divoperation:
			if (num2 != 0) // ÊÃßÏ ãä ÚÏã ÇáÞÓãÉ Úáì ÕÝÑ
			{
				cout << "\n" << num1 << "\n  / \n" << num2 << "\n__________\n";
				checkAnswer(num1, num2, randomOp, info);
			}
			else
			{
				cout << "Cannot divide by zero." << endl;
			}
			break;
		default:
			cout << "Invalid operation type!" << endl;
		}
	}

	else
	{
		{
			string opSymbol; // ÇáÑãÒ ÇáãÓÊÎÏã ááÚãáíÉ ÇáÍÓÇÈíÉ
			switch (quizform.type_of_questions)
			{
			case add:
				opSymbol = "+";
				break;
			case sub:
				opSymbol = "-";
				break;
			case mul:
				opSymbol = "*";
				break;
			case divoperation:
				opSymbol = "/";
				break;
			default:
				cout << "Invalid operation!" << endl;
				return;
			}

			// ÚÑÖ ÇáÓÄÇá
			cout << "\n" << num1 << "\n  " << opSymbol << " \n" << num2 << "\n__________\n";
			checkAnswer(num1, num2, quizform.type_of_questions, info);
		}

	}
}

void EasyQuestion(describtion quizform, container& info)
{
	int num1 = RandomNumber(1, 10);
	int num2 = RandomNumber(1, 10);
	show_question(num1, num2, quizform, info);
}
void medQuestion(describtion quizform, container& info)
{
	int num1 = RandomNumber(1, 50);
	int num2 = RandomNumber(1, 50);
	show_question(num1, num2, quizform, info);
}
void hardQuestion(describtion quizform, container& info)
{
	int num1 = RandomNumber(50, 100);
	int num2 = RandomNumber(50, 100);
	show_question(num1, num2, quizform, info);
}

void show_Pass(describtion quizform, container& info)
{
	cout << "\n\t\t\t_____________________________________\n";
	cout << "\n\t\t\t      Final results is pass :)\n";
	cout << "\n\t\t\t_____________________________________\n";
	cout << "\t\t\tNumber of qouestions  : " << quizform.num_of_questions << endl;
	cout << "\t\t\tQuestions level       : " << levelToString(quizform.level_Of_Quiz) << endl;
	cout << "\t\t\tType of questions     : " << typeToString(quizform.type_of_questions) << endl;
	cout << "\t\t\tRight answers         : " << info.right << endl;
	cout << "\t\t\tWrong answers         : " << info.wrong << endl;
	cout << "\n\t\t\t_____________________________________\n";
}
void show_Fail(describtion quizform, container& info)
{
	cout << "\n\t\t\t_____________________________________\n";
	cout << "\n\t\t\t       Final results is Fail :(\n";
	cout << "\n\t\t\t_____________________________________\n";
	cout << "\t\t\tNumber of qouestions  : " << quizform.num_of_questions << endl;
	cout << "\t\t\tQuestions level       : " << levelToString(quizform.level_Of_Quiz) << endl;
	cout << "\t\t\tType of questions     : " << typeToString(quizform.type_of_questions) << endl;
	cout << "\t\t\tRight answers         : " << info.right << endl;
	cout << "\t\t\tWrong answers         : " << info.wrong << endl;
	cout << "\n\t\t\t_____________________________________\n";
}

void generate_quiz()
{
	describtion quizform;
	quizform.YorN = 'n';

	do {
		container info = { 0, 0, 0, 0 };
		system("cls");
		system("color 0F");
		quizform = QuizForm();

		for (int i = 1; i <= quizform.num_of_questions; i++)
		{
			cout << "\n[Question " << i << "/" << quizform.num_of_questions << "]" << endl;
			if (quizform.level_Of_Quiz == easy)
			{
				EasyQuestion(quizform, info);
			}
			else if (quizform.level_Of_Quiz == med)
			{
				medQuestion(quizform, info);
			}
			else if (quizform.level_Of_Quiz == hard)
			{
				hardQuestion(quizform, info);
			}
			else
			{
				opetype randomy = (opetype)RandomNumber(1, 3);
				switch (randomy)
				{
				case easy:
					EasyQuestion(quizform, info);
					break;

				case med:
					medQuestion(quizform, info);
					break;
				case hard:
					hardQuestion(quizform, info);
					break;

				}
			}
		}
		if (info.right >= info.wrong)
		{
			show_Pass(quizform, info);
		}
		else
		{
			show_Fail(quizform, info);
		}


		cout << "Do you wnat to answer more questions ?" << endl;
		cin >> quizform.YorN;
	} while (quizform.YorN == 'y' || quizform.YorN == 'Y');
}



int main()
{

	srand((unsigned)time(NULL));


	generate_quiz();

	return 0;
}


