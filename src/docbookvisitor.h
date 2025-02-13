/******************************************************************************
*
* Copyright (C) 1997-2020 by Dimitri van Heesch.
*
* Permission to use, copy, modify, and distribute this software and its
* documentation under the terms of the GNU General Public License is hereby
* granted. No representations are made about the suitability of this software
* for any purpose. It is provided "as is" without express or implied warranty.
* See the GNU General Public License for more details.
*
* Documents produced by Doxygen are derivative works derived from the
* input used in their production; they are not affected by this license.
*
*/

#ifndef _DOCBOOKDOCVISITOR_H
#define _DOCBOOKDOCVISITOR_H

#include <iostream>

#include "containers.h"
#include "docvisitor.h"
#include "docparser.h"
#include "qcstring.h"

class CodeOutputInterface;
class QCString;
class TextStream;

/*! @brief Concrete visitor implementation for Docbook output. */
class DocbookDocVisitor : public DocVisitor
{
    public:
    DocbookDocVisitor(TextStream &t,CodeOutputInterface &ci,const QCString &langExt);
    ~DocbookDocVisitor();
    //--------------------------------------
    // visitor functions for leaf nodes
    //--------------------------------------
    void visit(DocWord *);
    void visit(DocLinkedWord *);
    void visit(DocWhiteSpace *);
    void visit(DocSymbol *);
    void visit(DocEmoji *);
    void visit(DocURL *);
    void visit(DocLineBreak *);
    void visit(DocHorRuler *);
    void visit(DocStyleChange *);
    void visit(DocVerbatim *);
    void visit(DocAnchor *);
    void visit(DocInclude *);
    void visit(DocIncOperator *);
    void visit(DocFormula *);
    void visit(DocIndexEntry *);
    void visit(DocSimpleSectSep *);
    void visit(DocCite *);
    //--------------------------------------
    // visitor functions for compound nodes
    //--------------------------------------
    void visitPre(DocAutoList *);
    void visitPost(DocAutoList *);
    void visitPre(DocAutoListItem *);
    void visitPost(DocAutoListItem *);
    void visitPre(DocPara *) ;
    void visitPost(DocPara *);
    void visitPre(DocRoot *);
    void visitPost(DocRoot *);
    void visitPre(DocSimpleSect *);
    void visitPost(DocSimpleSect *);
    void visitPre(DocTitle *);
    void visitPost(DocTitle *);
    void visitPre(DocSimpleList *);
    void visitPost(DocSimpleList *);
    void visitPre(DocSimpleListItem *);
    void visitPost(DocSimpleListItem *);
    void visitPre(DocSection *);
    void visitPost(DocSection *);
    void visitPre(DocHtmlList *);
    void visitPost(DocHtmlList *) ;
    void visitPre(DocHtmlListItem *);
    void visitPost(DocHtmlListItem *);
    //void visitPre(DocHtmlPre *);
    //void visitPost(DocHtmlPre *);
    void visitPre(DocHtmlDescList *);
    void visitPost(DocHtmlDescList *);
    void visitPre(DocHtmlDescTitle *);
    void visitPost(DocHtmlDescTitle *);
    void visitPre(DocHtmlDescData *);
    void visitPost(DocHtmlDescData *);
    void visitPre(DocHtmlTable *);
    void visitPost(DocHtmlTable *);
    void visitPre(DocHtmlRow *);
    void visitPost(DocHtmlRow *) ;
    void visitPre(DocHtmlCell *);
    void visitPost(DocHtmlCell *);
    void visitPre(DocHtmlCaption *);
    void visitPost(DocHtmlCaption *);
    void visitPre(DocInternal *);
    void visitPost(DocInternal *);
    void visitPre(DocHRef *);
    void visitPost(DocHRef *);
    void visitPre(DocHtmlHeader *);
    void visitPost(DocHtmlHeader *);
    void visitPre(DocImage *);
    void visitPost(DocImage *);
    void visitPre(DocDotFile *);
    void visitPost(DocDotFile *);
    void visitPre(DocMscFile *);
    void visitPost(DocMscFile *);
    void visitPre(DocDiaFile *);
    void visitPost(DocDiaFile *);
    void visitPre(DocLink *);
    void visitPost(DocLink *);
    void visitPre(DocRef *);
    void visitPost(DocRef *);
    void visitPre(DocSecRefItem *);
    void visitPost(DocSecRefItem *);
    void visitPre(DocSecRefList *);
    void visitPost(DocSecRefList *);
    //void visitPre(DocLanguage *);
    //void visitPost(DocLanguage *);
    void visitPre(DocParamSect *);
    void visitPost(DocParamSect *);
    void visitPre(DocParamList *);
    void visitPost(DocParamList *);
    void visitPre(DocXRefItem *);
    void visitPost(DocXRefItem *);
    void visitPre(DocInternalRef *);
    void visitPost(DocInternalRef *);
    void visitPre(DocText *);
    void visitPost(DocText *);
    void visitPre(DocHtmlBlockQuote *);
    void visitPost(DocHtmlBlockQuote *);
    void visitPre(DocVhdlFlow *);
    void visitPost(DocVhdlFlow *);
    void visitPre(DocParBlock *);
    void visitPost(DocParBlock *);

  private:
    //--------------------------------------
    // helper functions
    //--------------------------------------
    void filter(const QCString &str);
    void startLink(const QCString &file,
    const QCString &anchor);
    void endLink();
    void startMscFile(const QCString &fileName,const QCString &width,
    const QCString &height, bool hasCaption,const DocNodeList &children);
    void endMscFile(bool hasCaption);
    void writeMscFile(const QCString &fileName, DocVerbatim *s);
    void startDiaFile(const QCString &fileName,const QCString &width,
                      const QCString &height, bool hasCaption,const DocNodeList &children);
    void endDiaFile(bool hasCaption);
    void writeDiaFile(const QCString &fileName, DocVerbatim *s);
    void startDotFile(const QCString &fileName,const QCString &width,
    const QCString &height, bool hasCaption,const DocNodeList &children);
    void endDotFile(bool hasCaption);
    void writeDotFile(const QCString &fileName, DocVerbatim *s);
    void writePlantUMLFile(const QCString &fileName, DocVerbatim *s);
    void visitPreStart(TextStream &t,
                   const DocNodeList &children,
                   bool hasCaption,
                   const QCString &name,
                   const QCString &width,
                   const QCString &height,
                   bool inlineImage = FALSE);
    void visitPostEnd(TextStream &t, bool hasCaption, bool inlineImage = FALSE);
    void visitCaption(const DocNodeList &children);
    //--------------------------------------
    // state variables
    //--------------------------------------
    TextStream &m_t;
    CodeOutputInterface &m_ci;
    bool m_insidePre = false;
    bool m_hide = false;
    BoolStack m_enabled;
    QCString m_langExt;
    int m_colCnt = 0;
    BoolStack m_bodySet; // it is possible to have tables without a header, needs to be an array as we can have tables in tables
};

#endif
