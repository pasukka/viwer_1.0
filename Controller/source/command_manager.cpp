#include "command_manager.h"

CommandManager::~CommandManager() { delete command; }

void CommandManager::setCommand(Command *com) { command = com; }

void CommandManager::run() {
  if (command != 0) {
    command->execute();
  }
}
