/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | foam-extend: Open Source CFD
   \\    /   O peration     |
    \\  /    A nd           | For copyright notice see file Copyright
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of foam-extend.

    foam-extend is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation, either version 3 of the License, or (at your
    option) any later version.

    foam-extend is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with foam-extend.  If not, see <http://www.gnu.org/licenses/>.

Description
    private member of block. Creates boundary patches for the block

\*---------------------------------------------------------------------------*/

#include "error.H"
#include "block.H"


// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

void Foam::block::blockBoundary()
{
    label ni = blockDef_.n().x();
    label nj = blockDef_.n().y();
    label nk = blockDef_.n().z();

    // x-direction

    label wallLabel = 0;
    label wallCellLabel = 0;

    // x-min
    boundaryPatches_[wallLabel].setSize(nj*nk);
    for (label k = 0; k <= nk - 1; k++)
    {
        for (label j = 0; j <= nj - 1; j++)
        {
            boundaryPatches_[wallLabel][wallCellLabel].setSize(4);

            // set the points
            boundaryPatches_[wallLabel][wallCellLabel][0] =
                vtxLabel(0, j, k);
            boundaryPatches_[wallLabel][wallCellLabel][1] =
                vtxLabel(0, j, k + 1);
            boundaryPatches_[wallLabel][wallCellLabel][2] =
                vtxLabel(0, j + 1, k + 1);
            boundaryPatches_[wallLabel][wallCellLabel][3] =
                vtxLabel(0, j + 1, k);

            // update the counter
            wallCellLabel++;
        }
    }

    // x-max
    wallLabel++;
    wallCellLabel = 0;

    boundaryPatches_[wallLabel].setSize(nj*nk);

    for (label k = 0; k <= nk - 1; k++)
    {
        for (label j = 0; j <= nj - 1; j++)
        {
            boundaryPatches_[wallLabel][wallCellLabel].setSize(4);

            // set the points
            boundaryPatches_[wallLabel][wallCellLabel][0] =
                vtxLabel(ni, j, k);
            boundaryPatches_[wallLabel][wallCellLabel][1] =
                vtxLabel(ni, j+1, k);
            boundaryPatches_[wallLabel][wallCellLabel][2] =
                vtxLabel(ni, j+1, k+1);
            boundaryPatches_[wallLabel][wallCellLabel][3] =
                vtxLabel(ni, j, k+1);

            // update the counter
            wallCellLabel++;
        }
    }

    // y-direction

    // y-min
    wallLabel++;
    wallCellLabel = 0;

    boundaryPatches_[wallLabel].setSize(ni*nk);
    for (label i = 0; i <= ni - 1; i++)
    {
        for (label k = 0; k <= nk - 1; k++)
        {
            boundaryPatches_[wallLabel][wallCellLabel].setSize(4);

            // set the points
            boundaryPatches_[wallLabel][wallCellLabel][0] =
                vtxLabel(i, 0, k);
            boundaryPatches_[wallLabel][wallCellLabel][1] =
                vtxLabel(i + 1, 0, k);
            boundaryPatches_[wallLabel][wallCellLabel][2] =
                vtxLabel(i + 1, 0, k + 1);
            boundaryPatches_[wallLabel][wallCellLabel][3] =
                vtxLabel(i, 0, k + 1);

            // update the counter
            wallCellLabel++;
        }
    }

    // y-max
    wallLabel++;
    wallCellLabel = 0;

    boundaryPatches_[wallLabel].setSize(ni*nk);

    for (label i = 0; i <= ni - 1; i++)
    {
        for (label k = 0; k <= nk - 1; k++)
        {
            boundaryPatches_[wallLabel][wallCellLabel].setSize(4);

            // set the points
            boundaryPatches_[wallLabel][wallCellLabel][0] =
                vtxLabel(i, nj, k);
            boundaryPatches_[wallLabel][wallCellLabel][1] =
                vtxLabel(i, nj, k + 1);
            boundaryPatches_[wallLabel][wallCellLabel][2] =
                vtxLabel(i + 1, nj, k + 1);
            boundaryPatches_[wallLabel][wallCellLabel][3] =
                vtxLabel(i + 1, nj, k);

            // update the counter
            wallCellLabel++;
        }
    }

    // z-direction

    // z-min
    wallLabel++;
    wallCellLabel = 0;

    boundaryPatches_[wallLabel].setSize(ni*nj);

    for (label i = 0; i <= ni - 1; i++)
    {
        for (label j = 0; j <= nj - 1; j++)
        {
            boundaryPatches_[wallLabel][wallCellLabel].setSize(4);

            // set the points
            boundaryPatches_[wallLabel][wallCellLabel][0] =
                vtxLabel(i, j, 0);
            boundaryPatches_[wallLabel][wallCellLabel][1] =
                vtxLabel(i, j + 1, 0);
            boundaryPatches_[wallLabel][wallCellLabel][2] =
                vtxLabel(i + 1, j + 1, 0);
            boundaryPatches_[wallLabel][wallCellLabel][3] =
                vtxLabel(i + 1, j, 0);

            // update the counter
            wallCellLabel++;
        }
    }

    // z-max
    wallLabel++;
    wallCellLabel = 0;

    boundaryPatches_[wallLabel].setSize(ni*nj);

    for (label i = 0; i <= ni - 1; i++)
    {
        for (label j = 0; j <= nj - 1; j++)
        {
            boundaryPatches_[wallLabel][wallCellLabel].setSize(4);

            // set the points
            boundaryPatches_[wallLabel][wallCellLabel][0] =
                vtxLabel(i, j, nk);
            boundaryPatches_[wallLabel][wallCellLabel][1] =
                vtxLabel(i + 1, j, nk);
            boundaryPatches_[wallLabel][wallCellLabel][2] =
                vtxLabel(i + 1, j + 1, nk);
            boundaryPatches_[wallLabel][wallCellLabel][3] =
                vtxLabel(i, j + 1, nk);

            // update the counter
            wallCellLabel++;
        }
    }
}

// ************************************************************************* //
