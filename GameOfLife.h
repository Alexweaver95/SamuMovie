#ifndef GameOfLife_H
#define GameOfLife_H

/**
 * @brief Samu has learnt the rules of Conway's Game of Life
 *
 * @file GameOfLife.h
 * @author  Norbert Bátfai <nbatfai@gmail.com>
 * @version 0.0.1
 *
 * @section LICENSE
 *
 * Copyright (C) 2015, 2016 Norbert Bátfai, batfai.norbert@inf.unideb.hu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 * Samu (Nahshon) has learnt the rules of Conway's Game of Life. This is
 * an example of the paper entitled "Samu in his prenatal development".
 */

#include <QThread>
#include <QDebug>
#include <sstream>
#include "SamuQl.h"

class GameOfLife : public QThread
{
    Q_OBJECT

    int m_w {40}, m_h {30};

    bool ***lattices;
    int latticeIndex;
    void development();
    int  numberOfNeighbors ( bool **lattice,
                             int r, int c, bool s );
    void glider ( bool **lattice, int x, int y );
    void car ( bool **lattice, int x, int y );
    int carx {0};
    void man ( bool **lattice, int x, int y );
    int manx {0};
    void house ( bool **lattice, int x, int y );
    int housex {0};
    int many {0};


    void cloud(bool **lattice,int x, int y);
    int cloudx{0};

    void cloud2(bool **lattice,int x, int y);
    int cloudxx{0};


    void moon(bool **lattice, int x , int y);
    int moonx{0};

    void eso(bool **lattice, int x , int y);


    void tree(bool **lattice, int x , int y);
    int treex {0};
    int treexx {0};

    
    //Mario:
    void ground(bool **lattice, int x , int y);
    void ground2(bool **lattice, int x , int y);

    void lift(bool **lattice, int x , int y);
    int lifty{0};

    void mario(bool **lattice, int x , int y);
    int mariox{0};
    int marioy{0};


    //flappy bird:
    void bird(bool **lattice, int x , int y);
    int birdx {0};
    int birdy {0};
    void ground3(bool **lattice, int x , int y);

    //doodle jumo
    void doodle(bool **lattice, int x , int y);
    int doodlex{0};
    int doodley{0};
    void ground4(bool **lattice, int x , int y);





    bool **predictions;
    void learning();

    bool paused {false};

    QL** samuQl;

    long m_time {0};

    int m_delay {1};

public:
    GameOfLife ( int w = 30, int h = 20 );
    ~GameOfLife();

    void run();
    bool **lattice();
    int getW() const;
    int getH() const;
    long getT() const;
    void pause();
    int getDelay() const {
        return m_delay;
    }
    void setDelay ( int delay ) {
        if ( delay > 0 ) {
            m_delay = delay;
        }
    }

signals:
    void cellsChanged ( bool **, bool ** );

};

#endif // GameOfLife_H
