/* Copyright (c) 2022-2023 hors<horsicq@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef XINFODBTRANSFER_H
#define XINFODBTRANSFER_H

#include "xformats.h"
#include "xinfodb.h"

class XInfoDBTransfer : public QObject {
    Q_OBJECT
public:
    explicit XInfoDBTransfer(QObject *pParent = nullptr);

    enum COMMAND {
        COMMAND_ANALYZEALL = 0,
        COMMAND_ANALYZE,
        COMMAND_SYMBOLS, // TODO reload
        COMMAND_DISASM,
        COMMAND_REMOVE,
        COMMAND_CLEAR,
        COMMAND_EXPORT,
        COMMAND_IMPORT
    };

    struct OPTIONS {
        XBinary::FT fileType;
        QString sFileName;
        QIODevice *pDevice;
        XADDR nAddress;
        qint64 nSize;
        qint64 nCount;
    };

    void setData(XInfoDB *pXInfoDB, COMMAND transferType, const OPTIONS &options, XBinary::PDSTRUCT *pPdStruct);
    //    bool loadFromFile(QString sFileName,XBinary::FT fileType);

public slots:
    bool process();

signals:
    void errorMessage(const QString &sText);
    void completed(qint64 nElapsed);

private:
    XInfoDB *g_pXInfoDB;
    COMMAND g_transferType;
    OPTIONS g_options;
    XBinary::PDSTRUCT *g_pPdStruct;
};

#endif  // XINFODBTRANSFER_H
