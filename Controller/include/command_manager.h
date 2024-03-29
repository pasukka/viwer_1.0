#ifndef SRC_VIEW_INCLUDE_COMMAND_MANAGER_H
#define SRC_VIEW_INCLUDE_COMMAND_MANAGER_H

/**
 * @file command_manager.h
 * @author SevenStreams
 * @brief This file handles working with command manager
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */

/**
 * @brief The command interface
 */
class Command {
 public:
  /**
   * @brief The function handles initializing command
   *
   * @return Command
   */
  Command(){};

  /**
   * @brief The function handles destroying command
   *
   */
  virtual ~Command(){};

  /**
   * @brief The function handles executing command
   *
   */
  virtual void execute() = 0;
};

/**
 * @brief The command manager class
 */
class CommandManager {
 private:
  Command *command;

 public:
  /**
   * @brief The function handles initializing command manager
   *
   * @return CommandManager The command manager
   */
  CommandManager(){};

  /**
   * @brief The function handles destroying command manager
   *
   */
  ~CommandManager();

  /**
   * @brief The function handles setting command to command manager
   *
   * @param com The command
   */
  void setCommand(Command *com);

  /**
   * @brief The function handles running set command
   *
   */
  void run();
};

#endif  // SRC_VIEW_INCLUDE_COMMAND_MANAGER_H
