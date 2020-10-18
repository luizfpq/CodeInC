int calcPostFix(Stack stack) {
  StackInt       tempStackInt;
  int            auxInt, num1, num2;
  char           tempChar[MAX];

  tempStackInt =  createStackInt();
  auxInt = num1 = num2 = 0;

  while(stack->next != NULL) {
    
    tempChar[0] = popStack(stack);
    pushStack(stack, tempChar[0]);
    
    
    if(isdigit(tempChar[0]) || (tempChar[0] == ' ')) {
      pushCharToNum(stack, tempStackInt);
      tempChar[0] = popStack(stack);
      pushStack(stack, tempChar[0]);
    } else {
      num1 = popStackInt(tempStackInt);
      num2 = popStackInt(tempStackInt);
      tempChar[0] = popStack(stack);
      
      switch (tempChar[0]) {
      case '+':
        pushStackInt(tempStackInt, (num2+num1));
        break;
      case '-':
        pushStackInt(tempStackInt, (num2-num1));
        break;
      case '*':
        pushStackInt(tempStackInt, (num2*num1));
        break;
      case '/':
        pushStackInt(tempStackInt, (num2/num1));
        break;
      case '^':
        auxInt = num2;
        while (num1-- > 0) {
          auxInt *= num2;
        }
        pushStackInt(tempStackInt, auxInt);
        break;
      }
        
    }  
  }
  num1 = popStackInt(tempStackInt);
  return num1;
}