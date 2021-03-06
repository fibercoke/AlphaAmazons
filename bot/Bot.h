#ifndef ALPHAAMAZONS_BOT_H
#define ALPHAAMAZONS_BOT_H

#include <istream>
#include "common/Action.h"
#include "common/ChessBoard.h"
#include "MCTree.h"
#include "common/Player.h"

class Bot : public Player {
private:
    MCTree *tree;
public:
    explicit Bot(const ChessBoard &board = ChessBoard());

    ~Bot() {
        delete tree;
    }

    void doAction(const Action &act);

    const Action getAction(double sec);

    void request(const Action &act) override;

    const ChessBoard &getBoard() const override { return tree->getBoard(); }

    const Action response(double sec) override;

    void revert() override;

};

#endif //ALPHAAMAZONS_BOT_H
