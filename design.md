A shell is mainly interface that takes commands, parses them, and passes them to the operating system for execution.
This allows for a simple i/o flow:
    Constant Loop:
        - User Input
            - Check if first arg matches any commands
                - If so check if preceding args match command need
                    - If so, run command function with passed args
                    - If not, pass back error

                - If not, pass back error


Psuedo-Code:

    Constant Loop & Input:

        


        void loop() {
            while (running) { 
                input = getline();

                if (cmd_check(input)) {
                    if (arg_check(input)) {
                        execute(input);
                    } else {
                        exit("command args don't match requirement:")
                    }

                } else {
                    exit("no command matching:");
                }
            }
        }


