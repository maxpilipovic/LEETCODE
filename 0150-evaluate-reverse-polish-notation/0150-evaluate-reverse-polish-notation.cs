public class Solution {
    public int EvalRPN(string[] tokens) 
    {

        Stack<int> stack = new Stack<int>();

        for(int i = 0; i < tokens.Length; i++)
        {
            string currItem = tokens[i];

            if(stack.Count != 0 && currItem == "+" || currItem == "-" || currItem == "/" || currItem == "*")
            {
                //Pop second
                int secondNum = stack.Pop();

                //Pop first
                int firstNum = stack.Pop();

                int result = 0;

                if (currItem == "+")
                {
                    result = firstNum + secondNum;
                    stack.Push(result);
                }
                else if (currItem == "-")
                {
                    result = firstNum - secondNum;
                    stack.Push(result);
                }
                else if (currItem == "*")
                {   
                    result = firstNum * secondNum;
                    stack.Push(result);
                }
                else
                {
                    //Divide
                    result = firstNum / secondNum;
                    stack.Push(result);
                }

            }
            else
            {
                //If num

                //Convert int
                int c = Convert.ToInt32(currItem);  

                stack.Push(c);

            }
        }

        return stack.Pop();
    }
}