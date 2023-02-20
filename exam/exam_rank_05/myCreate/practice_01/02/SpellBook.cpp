#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
  ssize_t limit = book.size();

  for (ssize_t i = 0; i < limit; i++) {
    std::map<std::string, ASpell*>::iterator it = book.begin();
    delete it.operator->()->second;
    book.erase(it.operator->()->first);
  }
  book.clear();
}

void SpellBook::learnSpell(ASpell* spell) {
  if (spell == NULL) {
    return;
  }
  if (book.find(spell->getName()) != book.end()) {
    return;
  } else {
    book.insert(
        std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
  }
}

void SpellBook::forgetSpell(const std::string& spell_name) {
  std::map<std::string, ASpell*>::iterator it = book.find(spell_name);

  if (it != book.end()) {
    delete it.operator->()->second;
    book.erase(spell_name);
  }
  return;
}

ASpell* SpellBook::createSpell(const std::string& spell_name) {
  std::map<std::string, ASpell*>::iterator it = book.find(spell_name);
  if (it != book.end()) {
    return (it.operator->()->second->clone());
  } else {
    return (NULL);
  }
}
